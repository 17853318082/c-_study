/**
 * @file demo05.cpp
 * @author your name (you@domain.com)
 * @brief 指针常量与常量指针
 * @version 0.1
 * @date 2023-05-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>
using namespace std;

/*常量指针与指针常量*/
void d05test01(){
    // 指针常量：不能修改指针所指向的地址。在定义的同时必须初始化。
    char b = 'b';
    char c = 'c';
    char* const p = &b;   // 指针本身为常量，即指针指向的地址不可修改
    cout<<p<<endl;
    *p = 'c';             // 指针指向的地址的内容可以更改
    cout<<p<<endl;

    // 常量指针：不能修改指针所指向地址的内容。但可以改变指针所指向的地址。
    char a = 'a';
    const char* name2 = &a; // 指向的内容为常量，即p所指向的地址的值不能更改
    cout<<*name2<<endl;
    name2 = &c;          // 指针本身可以修改，即可以改变指针所指向的地址  
    cout<<*name2<<endl;
}

int main(){
    d05test01();
    return 0;
}