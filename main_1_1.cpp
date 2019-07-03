#include "C.h"
#include "SqList.h"
#include "Func1-1.h"

typedef int T;

int main_1_1() 
{
	bool i;
	int j, k;
	T e, e0;
	SqList<T> L;//˳������
	for (j = 1; j <= 5; ++j)
	{
		L.ListInsert(1, j);
	}
	cout << "��L�ı�ͷ����1-5��L = \n";
	L.ListTraverse(myPrint); 
	cout << "L�Ƿ�Ϊ�գ�" << boolalpha << L.ListEmpty() << ",��=" << L.ListLength() << endl;
	L.GetElem(4, e);
	cout << "��4��Ԫ�ص�ֵΪ" << e << endl;
	for (j = L.ListLength(); j <= L.ListLength() + 1; ++j)
	{
		k = L.LocateElem(j, equal);
		if (k) {
			cout << "ֵΪ" << j << "��Ԫ���Ǳ�L�ĵ�" << k << "��Ԫ��\n";
		}
		else
			cout << "û��ֵΪ" << j << "��Ԫ��\n";
	}
	for (j = 1; j < 2; ++j) {
		L.GetElem(j, e);
		i = L.NextElem(e, equal, e0);
		if (i)
			cout << "Ԫ��" << e << "�ĺ��Ϊ" << e0 << endl;
		else
			cout << "Ԫ��" << e << "û�к��\n";
	} 
	k = L.ListLength();
	for (j = k+1; j >= k; --j)
	{
		i = L.ListDelete(j, e);
		if (i) {
			cout << "ɾ����" << j << "��Ԫ�سɹ�����ֵΪ" << e << endl;
		}
		else {
			cout << "ɾ����" << j << "��Ԫ��ʧ��\n";
		}
	}
	L.ClearList();
	cout << endl << "��ձ�L��L�Ƿ�Ϊ�գ�" << boolalpha << L.ListEmpty();
	cout << "���� = " << L.ListLength() << endl;
	system("pause");
	return 0;
}
