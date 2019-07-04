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
		int i = 0;
		LNode<T> *p = Head->next;
		while (p != NULL) {
			p = p->next;
		}
	}
};
#endif // !_LINKLIST_H_
