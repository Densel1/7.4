
#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>



ShapeLSQ::ShapeLSQ(int _type, pointLSQ p_)
{
	p = p_;
    const char idx = 3;
    //����������� ����� �������
	switch (type)
	{
	case line:
		p_length = 2;
		break;
	case sqr:
		p_length = 4;
		break;
	case cube:
		p_length = 8;
		break;
	}

    Square(type);
    Volume(type);
};

// ������� �
int ShapeLSQ::sideA()
{
	return p.x[0] - p.x[1]; 
}

// ������� �
 int ShapeLSQ::sideB()
{
	return p.y[0] - p.y[1]; 
}

// ������� �
int ShapeLSQ::sideC()
{
	return p.z[0] - p.z[1]; 
}

// ������� ������
 double ShapeLSQ::Square(int type)
{
	// ������� ������
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
	}
	return square;
}

 double ShapeCC::Square(int type)
 {
	 // ������� ������

	 switch (type)
	 {
	 case circle:
		 square = M_PI * p.r * p.r;
		 break;
	 case cylinder:
		 square = M_PI * p.r * p.r + 2 * p.r * p.h;
		 break;
	 }
	 return square;
 }

 // ����� ������
 double ShapeLSQ::Volume(int type)
 {
	 switch (type)
	 {
	 case cube:
		 volume = sideA() * sideB() * sideC();
		 break;
	 default:
		 volume = 0;
	 }
	 return volume;
 }

 // ����� ������
 double ShapeCC::Volume(int type)
 {
	 switch (type)
	 {
	 case cylinder:
		 volume = M_PI * p.r * p.r * p.h;
		 break;
	 default:
		 volume = 0;
	 }
	 return volume;
 }


 
 void ShapeLSQ::shift(int m, int n, int k)
 {

	 for (unsigned int idx = 0; idx < p_length; idx++)
	 {
		 p.x[idx] += m; p.y[idx] += n; p.z[idx] += k;
	 }
 }

 void ShapeLSQ::scaleX(int a)
 {
	 for (unsigned int idx = 0; idx < p_length; idx++)
	 {
		 p.x[idx] *= a;
	 }
 }

 void ShapeLSQ::scaleY(int d)
 {
	 for (unsigned int idx = 1; idx < p_length; idx++)
	 {
		 p.y[idx] *= d;
	 }
 }

 void ShapeLSQ::scaleZ(int e)
 {
	 for (unsigned int idx = 2; idx < p_length; idx++)
	 {
		 p.z[idx] *= e;
	 }
 }

 void ShapeLSQ::scale(int s)
 {
	 for (unsigned int idx = 0; idx < p_length; idx++)
	 {
		 p.x[idx] /= s; p.y[idx] /= s; p.y[idx] /= s;
	 }
 }

