#pragma once
#include "Func1-1.h"

bool equal(double c1, double c2)
{
	return  abs(c1 - c2) < 1.0e-6;
}
bool equal(int c1, int c2)
{
	return c1 == c2;
}

//template <typename T>
//void myPrint(T* c)
