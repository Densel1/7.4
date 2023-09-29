
#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>


Shape::Shape(int _type, int p_[])
{
	type = _type;
    const char idx = 3;
    //расчитываем длину массива
	switch (type)
	{
	case line:
		p_length = 2*idx;
		break;
	case sqr:
		p_length = 4*idx;
		break;
	case cube:
		p_length = 8*idx;
		break;
	case circle:
		p_length = 3*idx;
		break;
	case cylinder:
		p_length = 4*idx;
		break;
	}
	// заполн¤ем координаты фигуры
	for (unsigned int i = 0; i < p_length; ++i)
	{
		p[i] = p_[i];
	}


    Square(type);
    Volume(type);
};

// сторона а
int Shape::sideA()
{
	return p[0] - p[3]; //8
}

// сторона Б
 int Shape::sideB()
{
	return p[1] - p[4]; //8
}

// сторона С
int Shape::sideC()
{
	return p[2] - p[5]; //8
}

// площадь фигуры
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

// объем фигуры
double Shape::Volume(int type)
{
	switch (type)
	{
	case cube:
		volume = sideA() * sideB() * sideC();
		break;
	case cylinder:
		volume = M_PI * p[2] * p[2] * p[3];
		break;
	default:
		volume = 0;
	}
	return volume;
}
