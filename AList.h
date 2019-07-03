#pragma once
//AList.h ���Ա������
#ifndef _ALIST_H_
#define _ALIST_H_
template<typename T> 
class AList//��ģ������Ա������
{
public:
	//�������Ա�Ϊ�ձ�
	void ClearList();
	//�ж��Ƿ�Ϊ�ձ�
	bool ListEmpty() const;
	int LocateElem(T e, bool(*eq)(T, T))const;//���ص�һ����һ����e�����ϵeq()������Ԫ�ص�λ��
	bool PriorElem(T e, bool(*eq)(T, T), T &pre_e) const;//��pre_e�������Ԫ�ص�ǰ��
	bool NextElem(T e, bool(*eq)(T, T), T &pre_e) const;//
	bool ListDelete(int i, T &e);//ɾ����i��Ԫ��
	void ListTraverse(void(*visit)(T*))const;//��������ÿ��Ԫ�ص���visit()
	virtual bool GetElem(int i, T &e)const = 0;//virtual + ��=0�����Ǵ��麯����
	virtual bool ListInsert(int i, T e) = 0;//�ڵ�i��Ԫ��ǰ�����µ�Ԫ��e
	virtual int ListLength() const = 0;//�������Ա�ĳ���
};
#endif // !_ALIST_H_

