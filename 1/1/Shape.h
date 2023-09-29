#pragma once

#include<string>
#include<vector>


class Shape
{
public:


	Shape() = default;
	Shape(int type, int p[]);
	int getType() { return type; }
	double Square(int type);
	double Volume(int type);
	unsigned int p_length = 0;
	int p[24];
private:
	int sideA();
	int sideB();
	int sideC();
	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;
	int type;

	double volume = 0;
	double square = 0;
};
