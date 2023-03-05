/*
    ָ�룬����

*/

#include<iostream>

using namespace std;

void test01()
{
    /*
        һ�����͵�ָ��ֻ��ָ����ͬ����
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
        ָ���ʼ��
    */

    int* p = { nullptr };   // ָ����Գ�ʼ��Ϊ��
    int a = 10;
    p = &a;
    cout << *p << endl;
}

void test03()
{
    /*
    ʹ��new�����ڴ棬�Լ�delete�ͷ��ڴ�
    */
    int* p = new int;   // ����һ����СΪint ���ڴ棬����ָ��pָ������ڴ�
    cout << p << endl;
    *p = 1001;         // Ϊָ��ָ������ݶ�����һ��ֵ
    cout << *p << endl;
    delete p;         // �ڴ����ͷ�   ��deleteֻ���ͷ�ʹ��new������ڴ�
    cout << p << endl;   // ָ��p��Ȼָ�����ĵ�ַ,���ǵ�ַ�Ѿ����ͷ�
    cout << *p << endl;   // ����������ط����޷���ȡ��ַ�е�ֵ������������ ��Ϊ���ڴ��Ѿ����ͷ�
}
void test04()
{
    /*
    ʹ��new������̬����
    */
    int* p = new int[10]; // pָ���СΪ10��int������׵�ַ
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i <10 ; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p; // ɾ������p
}
void test05()
{
    /*
    ���������ָ�������һЩ���
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
        p = p + 1;                    // ָ���������ͨ��ָ����ƶ�ʵ�ַ�������Ԫ��
        j++;
    }
    delete[] p;
    j = 0;
    while (j < 10)
    {
        cout << *q << endl;            // ����ͨ�� *������ͷ��ַԪ��
        // q = q + 1;                  // �����鲻��ͨ���ƶ�ͷ��ַ��������Ԫ��
        j++;
    }
    //cout << &q << endl;
    //cout << "����ĳ���Ϊ��" << sizeof(p) << endl;
}
constexpr void test07(int& b)
{
    // ���ʹ��const int& b ���޷��ı����õ�ֵ������ʹ��
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
    const ����
    */
    int a;
    int b = 1;  // ����ڹ�����������仯�򣬱������Ὣ����Ϊconst����  ��const int b=1;
    cout << b << endl;
    a = 0;
    cout << a << endl;
    test07(a);
    cout << a << endl;   // �޸ĺ�
    
    /*
    ��������
    */
    int c;
    // ����test08()�������ü��൱��һ�����������Խ�����ֵ
    test08(c) = 10;
    // �������һ��Ӧ�ý��գ���
    int& d = test08(c);
    test08(c) = 10;
    cout << c << endl;
    cout << "d��ֵΪ��" << d<<endl;    // d��c��test08()����ͬһ���ַ��ֻ�����ֲ�ͬ
}

/*
   ָ������ָ��
*/
constexpr int test09(int b)
{
    const int a = b;
    return a;
}
void test11(int (*p)(int))
{
    //test11���Խ���һ�� ����ֵ����Ϊint����һ������Ϊint�ĺ���ֵ
    const int c = p(10);
    cout << c << endl;    // ���10
    
}
void test10()
{
    int (*pFun)(int);  // ָ������ָ������,���Խ���һ��int���͵Ĳ���
    const int b = 3;
    pFun = test09;   // test09 ����������ʾ�����ĵ�ַ���������ţ�
    cout << pFun << endl;  // ��ʾ��ú����ĵ�ַ  
    cout << (*pFun)(b) << endl;  // ��ú����ķ���ֵ  pFun��ʾ����ָ��  *(pFun)��ʾ����   pFun()��*(pFun)()������

    // ������test09����test11
    test11(pFun);
}
