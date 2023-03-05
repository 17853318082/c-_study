/*
  c++11新特性学习
  智能指针
*/

#include<iostream>
#include<memory>
using namespace std;

// 自定义释放规则
void deleteInt(int* p) {
	// 删除指针p指向的连续数组
	delete[] p;
}

void d3test01() {
	int* ptr = new int;
	*ptr = 1;
	shared_ptr<int> p1(ptr);  // 使用估值构造函数
	cout << *p1 << endl;
	*p1 = 2;
	cout << *p1 << endl;

	// 自定义释放规则
	shared_ptr<int> p2(new int[10], deleteInt);
	*p2 = 5;
	cout << *p2 << endl;


}