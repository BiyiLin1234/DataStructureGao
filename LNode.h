#pragma once
//LNode.h ������ڵ����ͽṹ��
#ifndef _LNODE_H_
#define _LNODE_H_
template<typename T>
struct LNode//������ڵ����ͽṹ��
{
	T data;
	LNode<T> * next;
};
#endif