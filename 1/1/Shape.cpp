
#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>


Shape::Shape(int _type, int p_[])
{
	type = _type;
	// заполн¤ем координаты фигуры
	switch (type)
	{
	case line:
		p_length = 2*3;
		break;
	case sqr:
		p_length = 4*3;
		break;
	case cube:
		p_length = 8*3;
		break;
	case circle:
		p_length = 3*3;
		break;
	case cylinder:
		p_length = 4*3;
		break;
	}

	for (unsigned int i = 0; i < p_length; ++i)
	{
		p[i] = p_[i];
	}

};

int Shape::sideA()
{
	return p[0] - p[3]; //8
}

 int Shape::sideB()
{
	return p[1] - p[4]; //8
}

int Shape::sideC()
{
	return p[2] - p[5]; //8
}


 double Shape::Square(int type)
{

	// стороны фигуры

	switch (type)
	{
	case line:
		square = 0;
		break;
	case sqr:
		square = sideA() * sideB();
		break;
	case cube:
		square = 2 * sideA() * sideB() + 2 * sideA() * sideC() + 2 * sideB() * sideC();
		break;
	case circle:
		square = M_PI * p[2] * p[2];
		break;
	case cylinder:
		square = M_PI * p[2] * p[2] + 2 * p[2] * p[3];
		break;
	}
	return square;
}

double Shape::Volume(int type)
{
	switch (type)
	{
	case line:
		volume = 0;
		break;
	case sqr:
		volume = 0;
		break;
	case cube:
		volume = sideA() * sideB() * sideC();
		break;
	case circle:
		volume = 0;
		break;
	case cylinder:
		volume = M_PI * p[2] * p[2] * p[3];
		break;
	}
	return volume;
}
