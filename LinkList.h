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
		//����
		Head = new LNode<T>;
		assert(Head != NULL);
		Head->next = NULL;
	}
	~LinkList() {
		//ͷ�ڵ㱾���洢ֵ������deleteͷ�ڵ�֮�������ֵ����delete��ͷ�ڵ�����ˡ�
		ClearList();
		delete Head;
	}
	void ClearList()const
	{
		//ͷ�ڵ㱾���洢ֵ��
		LNode<T> *q, *p = Head->next;
		Head->next = NULL;
		while (p != NULL) {
			//ֻҪp���գ�����qָ��p->next��Ȼ��delete p��Ȼ��p = q�ټ����ж�
			q = p->next;
			delete p;
			p = q;
		}
	}
	bool ListEmpty()const {
		return  Head->next == NULL;
	}
	int ListLength() const {
		//ѭ��һ��
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
