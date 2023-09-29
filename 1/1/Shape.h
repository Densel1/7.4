#pragma once

#include<string>
#include<vector>


class Shape
{
public:


	Shape() = default;
	Shape(int type, int p[]);
	Shape(int type, int _x1, int _y1, double R, double H);
	int getType() { return type; }
	double Square(int type);
	double Volume(int type);
	int sideA();
	int sideB();
	int sideC();
	int sideS();
	unsigned int p_length = 0;
	int p[24];
private:

	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;
	int type;
	double volume = 0;
	double square = 0;
	double height = 0;
	double radius = 0;


};
