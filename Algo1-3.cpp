#include "C.h"
struct Student
{
	string name;
	int score;
};
//bС��a�Ļ�����0
bool cmp(const Student &a, const Student &b)
{
	return a.score <= b.score;
}
int main()
{
	vector<Student> a;
	vector<Student>::iterator ip;
	ifstream fin("F://dataStructure//DataStructureGao//DataStructureGao//F1-1.txt");
	Student e;
	while (!fin.eof())
	{
		fin >> e.name >> e.score;
		a.push_back(e);
	}
	fin.close();
	for (ip = a.begin(); ip != a.end(); ip++) {
		cout << ip->name << ":" << ip->score << endl;
	}
	ip = a.begin() + 2;
	e.name = "������";
	e.score = 99;
	a.insert(ip, e);
	a.erase(a.begin() + 4);//ɾ�������Ԫ��
	cout << "ɾ���� �� \n";
	for (Student i : a) {
		cout << i.name << ":" << i.score << endl;
	}
	cout << "a.front()=" << a.front().name << ":" << a.front().score << endl;
	sort(a.begin(), a.end(), cmp);
	cout << "�����������\n";
	for (auto i : a) {
		cout << i.name << ":" << i.score << endl;
		
	}
	system("pause");
}