#pragma once
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "AList.h"
#include "LNode.h"
template<typename T> 
class LinkList :public AList<T>
{
	friend void MergeList(LinkList<T>&, LinkList<T>&);
protected:
	LNode<T> *Head;
public:
	LinkList() {
		//构造
		Head = new LNode<T>;
		assert(Head != NULL);
		Head->next = NULL;
	}
	~LinkList() {
		//头节点本身不存储值，所以delete头节点之后的所有值后，再delete掉头节点就行了。
		ClearList();
		delete Head;
	}
	void ClearList()const
	{
		//头节点本身不存储值，
		LNode<T> *q, *p = Head->next;
		Head->next = NULL;
		while (p != NULL) {
			//只要p不空，就用q指向p->next，然后delete p，然后p = q再继续判断
			q = p->next;
			delete p;
			p = q;
		}
	}
	bool ListEmpty()const {
		return  Head->next == NULL;
	}
	int ListLength() const {
		//循环一遍
		int i = 0;
		LNode<T> *p = Head->next;
		while (p != NULL) {
			p = p->next;
			i++;
		}
		return i;
	}
	bool GetElem(int i, T&e) const
	{
		LNode<T> * p;
		p = Head;
		for (int j = 0; j < i; ++j) {
			if (p->next == NULL) {
				return false;
			}
			p = p->next;
		}
		e = p->data;
		return true;
	}
	int LocateElem(T e, bool(*eq)(T, T)) const
	{

	}
	bool PriorElem(T e, bool(*eq)(T, T), T & pre_e)const
	{

	}
	bool NextElem(T e, bool(*eq)(T, T), T&next_e)const
	{

	}
	bool ListInsert(int i, T e) {

	}
	bool ListDelete(int i, T&e)const
	{

	}
	void ListTraverse(void(*visit)(T*)) const {

	}
};

#endif // !_LINKLIST_H_
