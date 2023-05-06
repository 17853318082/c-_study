/*
const 操作
*/
#include<iostream>
using namespace std;

/*常量指针与指针常量*/
void d05test01(){
    // 常量指针:
    char b = 'b';
    char c = 'c';
    char* const p = &b; // 指针本身为常量，即指针指向的地址不可修改
    cout<<p<<endl;
    *p = 'c';             // 指针指向的地址的内容可以更改
    cout<<p<<endl;
    // name = "lin";
    // cout<<name<<endl;
    // char* name1 = "tom";
    // cout<<&name1<<endl;
    // name1 = "lin";
    // cout<<&name1<<endl;

    // 指针常量
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