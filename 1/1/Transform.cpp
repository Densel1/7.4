#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{

		for (unsigned int idx = 0; idx < shape.p_length; idx += 3)
		{
			shape.p[idx] += m; shape.p[idx + 1] += n; shape.p[idx + 2] += k;
		}

	return shape;
}

Shape transform::scaleX(int a)
{
	for (unsigned int idx = 0; idx < shape.p_length; idx += 3)
	{
		shape.p[idx] *= a;
	}
	return shape;
}

Shape transform::scaleY(int d)
{
	for (unsigned int idx = 1; idx < shape.p_length; idx += 3)
	{
		shape.p[idx] *= d;
	}
	return shape;
}

Shape transform::scaleZ(int e)
{
	for (unsigned int idx = 2; idx < shape.p_length; idx += 3)
	{
		shape.p[idx] *= e;
	}
	return shape;
}

Shape transform::scale(int s)
{

	for (unsigned int idx = 0; idx < shape.p_length; idx += 3)
	{
		shape.p[idx] /= s; shape.p[idx + 1] /= s; shape.p[idx + 2] /= s;
	}


	return shape;
}