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
	//构造函数，传入参数为表容量大小
	SqList(int k = 1)//表初始容量为1，方便乘2.
	{
		elem = new T[k];
		length = 0;
		listSize = k;
	}
	//析构函数
	~SqList()
	{
		delete[]elem;
	}
	//重置为空表
	void ClearList()
	{
		length = 0;
	}
	//判断表是否位空
	bool ListEmpty() const
	{
		return length == 0;
	}
	//表长
	int ListLength() const
	{
		return length;
	}
	//获取元素
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
	//获取第一个传入元素位置
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
	//若e与表中某元素满足eq()，且该元素不是第一个，返回其该元素前驱
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
	//插入元素到位序i上，如果表满，扩大两倍
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
	//删除元素
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
		length--;//length减1就行，最后一位不管是什么。
	}
	//遍历元素
	void ListTraverse(void(*visit)(T*)) const;
};

template<typename T>
//visit仅仅是形参名称，实际可以是print等名称
void SqList<T>::ListTraverse(void(*visit)(T*)) const
{
	for (int i = 0; i < length; ++i)
		visit(elem + i);
	cout << endl;
}
#endif