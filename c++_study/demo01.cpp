/*
    指针，引用

*/

#include<iostream>

using namespace std;

void test01()
{
    /*
        一个类型的指针只能指向相同类型
    */
    int* p;    // 
    int a = 3;
    double b = 4;
    p = &a;
    cout << *p << endl;
    // p = &b;
    cout << *p << endl;
}

void test02()
{
    /*
        指针初始化
    */

    int* p = { nullptr };   // 指针可以初始化为空
    int a = 10;
    p = &a;
    cout << *p << endl;
}

void test03()
{
    /*
    使用new分配内存，以及delete释放内存
    */
    int* p = new int;   // 分配一个大小为int 的内存，并将指针p指向这块内存
    cout << p << endl;
    *p = 1001;         // 为指针指向的数据对象赋予一个值
    cout << *p << endl;
    delete p;         // 内存已释放   ，delete只能释放使用new分配的内存
    cout << p << endl;   // 指针p仍然指向分配的地址,但是地址已经被释放
    cout << *p << endl;   // 所以在这个地方，无法读取地址中的值，程序死锁， 因为该内存已经被释放
}
void test04()
{
    /*
    使用new创建动态数组
    */
    int* p = new int[10]; // p指向大小为10的int数组的首地址
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i <10 ; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p; // 删除数组p
}
void test05()
{
    /*
    测试数组和指针数组的一些差别
    */
    int q[10];
    int* p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        q[i] = i;
        p[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << q[i] << " " << p[i] << endl;
    }
    int j = 0;
    while (j < 10)
    {
        cout << *p << endl;
        p = p + 1;                    // 指针数组可以通过指针的移动实现访问所有元素
        j++;
    }
    delete[] p;
    j = 0;
    while (j < 10)
    {
        cout << *q << endl;            // 可以通过 *来访问头地址元素
        // q = q + 1;                  // 而数组不能通过移动头地址访问数组元素
        j++;
    }
    //cout << &q << endl;
    //cout << "数组的长度为：" << sizeof(p) << endl;
}
constexpr void test07(int& b)
{
    // 如果使用const int& b 则无法改变引用的值，仅能使用
    b = 10;
}
int& test08(int& c)
{
    c = 5;
    cout << c << endl;
    return c;
}
void test06()
{
    /*
    const 引用
    */
    int a;
    int b = 1;  // 如果在构造后变量不会变化则，编译器会将其标记为const常量  即const int b=1;
    cout << b << endl;
    a = 0;
    cout << a << endl;
    test07(a);
    cout << a << endl;   // 修改后
    
    /*
    接收引用
    */
    int c;
    // 函数test08()返回引用即相当于一个变量，可以接收右值
    test08(c) = 10;
    // 如果声明一个应用接收，即
    int& d = test08(c);
    test08(c) = 10;
    cout << c << endl;
    cout << "d的值为：" << d<<endl;    // d与c与test08()共用同一块地址，只是名字不同
}

/*
   指向函数的指针
*/
constexpr int test09(int b)
{
    const int a = b;
    return a;
}
void test11(int (*p)(int))
{
    //test11可以接收一个 返回值类型为int，有一个参数为int的函数值
    const int c = p(10);
    cout << c << endl;    // 输出10
    
}
void test10()
{
    int (*pFun)(int);  // 指向函数的指针声明,可以接受一个int类型的参数
    const int b = 3;
    pFun = test09;   // test09 仅函数名表示函数的地址（不带括号）
    cout << pFun << endl;  // 表示获得函数的地址  
    cout << (*pFun)(b) << endl;  // 获得函数的返回值  pFun表示函数指针  *(pFun)表示函数   pFun()与*(pFun)()都可以

    // 将函数test09传入test11
    test11(pFun);
}
