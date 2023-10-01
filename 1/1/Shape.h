#pragma once

#include<string>

class pointLSQ
{
public:
	pointLSQ() = default;
	pointLSQ(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6, int x7, int y7, int z7, int x8, int y8, int z8)
	{
		x[0] = x1; y[0] = y1; z[0] = z1;
		x[1] = x2; y[1] = y2; z[1] = z2;
		x[2] = x3; y[2] = y3; z[2] = z3;
		x[3] = x4; y[3] = y4; z[3] = z4;
		x[4] = x5; y[4] = y5; z[4] = z5;
		x[5] = x6; y[5] = y6; z[5] = z6;
		x[6] = x7; y[6] = y7; z[6] = z7;
		x[7] = x8; y[7] = y8; z[7] = z8;
	}

	int x[8];
	int y[8];
	int z[8];
};

class pointCC
{
public:
	pointCC() = default;
	pointCC(int x_, int y_, int r_, int h_)
	{
		x = x_;
		y = y_;
		r = r_;
		h = h_;
	}
	int x;
	int y;
	int r = 0;
	int h = 0;
};


class Shapebase
{
public:
	Shapebase() = default;
protected:
	int type;
	unsigned int p_length = 0;
	double volume = 0;
	double square = 0;
};

class ShapeCC :public Shapebase
{
public:
	ShapeCC(int type, pointCC p);
	double Square(int type);
	double Volume(int type);
private:
	static const int circle = 3;
	static const int cylinder = 4;
	pointCC p;
};

class ShapeLSQ:public Shapebase
{
public:
	ShapeLSQ(int type, pointLSQ p);
	double Square(int type) ;
	double Volume(int type) ;
	void shift(int m, int n, int k);
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);

private:
	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	int getType() { return type; }
	int sideA();
	int sideB();
	int sideC();

	pointLSQ p;
};

