/**
 * @file demo03.cpp
 * @author shiyu (you@domain.com)
 * @brief 智能指针
 * @version 0.1
 * @date 2023-05-16
 * 
 * @copyright Copyright (c) 2023
 * 
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

/**
 * @brief unique_ptr
 * 注意事项：unique_ptr不支持拷贝和赋值
 */
void d3test02(){
	// 创建unique_ptr
	unique_ptr<string> p1(new string("unqiue_ptr_source"));
	// 读取unique_ptr资源  --  获取值的方式与普通指针相同
	cout<<*p1<<endl;
}

int main(){
	d3test02();
}