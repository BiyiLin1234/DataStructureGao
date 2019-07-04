#pragma once
//LNode.h 单链表节点类型结构体
#ifndef _LNODE_H_
#define _LNODE_H_
template<typename T>
struct LNode//单链表节点类型结构体
{
	T data;
	LNode<T> * next;
};
#endif