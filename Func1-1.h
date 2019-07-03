#pragma once
//三个常用的函数================================
#include <iostream>

bool equal(double c1, double c2)
{
	return  abs(c1 - c2) < 1.0e-6;
}
bool equal(int c1, int c2)
{
	return c1 == c2;
}
template<typename T>
inline void myPrint(T* c)
{
	std::cout << *c << " ";
}
//==============================================