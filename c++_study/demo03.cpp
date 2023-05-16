/**
 * @file demo03.cpp
 * @author shiyu (you@domain.com)
 * @brief ����ָ��
 * @version 0.1
 * @date 2023-05-16
 * 
 * @copyright Copyright (c) 2023
 * 
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

/**
 * @brief unique_ptr
 * ע�����unique_ptr��֧�ֿ����͸�ֵ
 */
void d3test02(){
	// ����unique_ptr
	unique_ptr<string> p1(new string("unqiue_ptr_source"));
	// ��ȡunique_ptr��Դ  --  ��ȡֵ�ķ�ʽ����ָͨ����ͬ
	cout<<*p1<<endl;
}

int main(){
	d3test02();
}