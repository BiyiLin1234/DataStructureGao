#pragma once
//AList.h 线性表抽象类
#ifndef _ALIST_H_
#define _ALIST_H_
template<typename T> 
class AList//带模板的线性表抽象类
{
public:
	//重置线性表为空表
	void ClearList();
	//判断是否为空表
	bool ListEmpty() const;
	int LocateElem(T e, bool(*eq)(T, T))const;//返回第一个第一个与e满足关系eq()的数据元素的位序
	bool PriorElem(T e, bool(*eq)(T, T), T &pre_e) const;//用pre_e返回相等元素的前驱
	bool NextElem(T e, bool(*eq)(T, T), T &pre_e) const;//
	bool ListDelete(int i, T &e);//删除第i个元素
	void ListTraverse(void(*visit)(T*))const;//遍历，对每个元素调用visit()
	virtual bool GetElem(int i, T &e)const = 0;//virtual + “=0”，是纯虚函数了
	virtual bool ListInsert(int i, T e) = 0;//在第i个元素前插入新的元素e
	virtual int ListLength() const = 0;//返回线性表的长度
};
#endif // !_ALIST_H_

