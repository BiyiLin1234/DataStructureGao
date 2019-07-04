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
		int i = 0;
		LNode<T> *p = Head->next;
		while (p != NULL) {
			p = p->next;
		}
	}
};
#endif // !_LINKLIST_H_
