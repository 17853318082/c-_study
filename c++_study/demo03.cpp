/*
  c++11������ѧϰ
  ����ָ��
*/

#include<iostream>
#include<memory>
using namespace std;

// �Զ����ͷŹ���
void deleteInt(int* p) {
	// ɾ��ָ��pָ�����������
	delete[] p;
}

void d3test01() {
	int* ptr = new int;
	*ptr = 1;
	shared_ptr<int> p1(ptr);  // ʹ�ù�ֵ���캯��
	cout << *p1 << endl;
	*p1 = 2;
	cout << *p1 << endl;

	// �Զ����ͷŹ���
	shared_ptr<int> p2(new int[10], deleteInt);
	*p2 = 5;
	cout << *p2 << endl;


}