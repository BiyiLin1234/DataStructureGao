#ifndef _SQLIST_H_
#define _SQLIST_H_
#include "AList.h"
#include <iostream>

template<typename T>
class SqList:public AList<T>
{
private:
	int listSize;
	int length;
	T * elem;
public:
	//���캯�����������Ϊ��������С
	SqList(int k = 1)//���ʼ����Ϊ1�������2.
	{
		elem = new T[k];
		length = 0;
		listSize = k;
	}
	//��������
	~SqList()
	{
		delete[]elem;
	}
	//����Ϊ�ձ�
	void ClearList()
	{
		length = 0;
	}
	//�жϱ��Ƿ�λ��
	bool ListEmpty() const
	{
		return length == 0;
	}
	//��
	int ListLength() const
	{
		return length;
	}
	//��ȡԪ��
	bool GetElem(int i, T&e)const
	{
		if (i <= length && i >= 0)
		{
			e = *(elem + i - 1);
			return true;
		}
		else
		{
			return false;
		}
	}
	//��ȡ��һ������Ԫ��λ��
	int LocateElem(T e, bool(*eq)(T, T)) const
	{
		int i = 1;
		while (i <= length) 
		{
			if (eq(*(elem + i-1), e)) 
			{
				return i;
			}
			i++;
		}
		return 0;
	}
	//��e�����ĳԪ������eq()���Ҹ�Ԫ�ز��ǵ�һ�����������Ԫ��ǰ��
	bool PriorElem(T e, bool(*eq)(T, T), T &pre_e) const
	{
		int i = LocateElem(e, eq);
		if (i <= 1 || i>length)
			return 0;
		else 
		{
			pre_e = *(elem + i - 2);
			return 1;
		}
	}
	bool NextElem(T e, bool(*eq)(T, T), T &next_e) const
	{
		int i = LocateElem(e, eq);
		if (i < 1 || i >= length)
		{
			return 0;
		}
		else 
		{
			next_e = *(elem + i);
			return 1;
		}
	}
	//����Ԫ�ص�λ��i�ϣ������������������
	bool ListInsert(int i, T e)
	{
		if (i<1 || i>length+1)
			return 0;
		if (listSize == length)
		{
			T * newbase = new T[length * 2];
			assert(newbase != NULL);
			for (int j = 0; j < length; ++j) {
				*(newbase + j) = *(elem + j);
			}
			delete[]elem;
			elem = newbase;
			listSize *= 2;
		}
		for (T * p = elem + length; p >= elem + i; --p)
		{
			*(p) = *(p - 1);
		}
		*(elem + i - 1) = e;
		length += 1;
		return 1;
	}
	//ɾ��Ԫ��
	bool ListDelete(int i, T&e)
	{
		if (i<1 || i>length) {
			return false;
		}
		T * q = elem + length - 1;
		for (T* p = (elem + i - 1); p < q; ++p)
		{
			*(p) = *(p + 1);
		}
		length--;//length��1���У����һλ������ʲô��
	}
	//����Ԫ��
	void ListTraverse(void(*visit)(T*)) const;
};

template<typename T>
//visit�������β����ƣ�ʵ�ʿ�����print������
void SqList<T>::ListTraverse(void(*visit)(T*)) const
{
	for (int i = 0; i < length; ++i)
		visit(elem + i);
	cout << endl;
}
#endif