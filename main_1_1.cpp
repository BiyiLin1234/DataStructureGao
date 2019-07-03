#include "C.h"
#include "SqList.h"
#include "Func1-1.h"

typedef int T;

int main_1_1() 
{
	bool i;
	int j, k;
	T e, e0;
	SqList<T> L;//顺序表对象
	for (j = 1; j <= 5; ++j)
	{
		L.ListInsert(1, j);
	}
	cout << "在L的表头插入1-5后，L = \n";
	L.ListTraverse(myPrint); 
	cout << "L是否为空？" << boolalpha << L.ListEmpty() << ",表长=" << L.ListLength() << endl;
	L.GetElem(4, e);
	cout << "第4个元素的值为" << e << endl;
	for (j = L.ListLength(); j <= L.ListLength() + 1; ++j)
	{
		k = L.LocateElem(j, equal);
		if (k) {
			cout << "值为" << j << "的元素是表L的第" << k << "个元素\n";
		}
		else
			cout << "没有值为" << j << "的元素\n";
	}
	for (j = 1; j < 2; ++j) {
		L.GetElem(j, e);
		i = L.NextElem(e, equal, e0);
		if (i)
			cout << "元素" << e << "的后继为" << e0 << endl;
		else
			cout << "元素" << e << "没有后继\n";
	} 
	k = L.ListLength();
	for (j = k+1; j >= k; --j)
	{
		i = L.ListDelete(j, e);
		if (i) {
			cout << "删除第" << j << "个元素成功，其值为" << e << endl;
		}
		else {
			cout << "删除第" << j << "个元素失败\n";
		}
	}
	L.ClearList();
	cout << endl << "清空表L后，L是否为空？" << boolalpha << L.ListEmpty();
	cout << "，表长 = " << L.ListLength() << endl;
	system("pause");
	return 0;
}
