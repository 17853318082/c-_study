/*
  异常处理
*/

#include<iostream>
#include<string>
using namespace std;
#ifdef DEBUG
void d2test01();
#endif // DEBUG


void d2test01() {
	/*
	  有异常处理
	*/
	cout << "异常处理" << endl;
	int a, b;
	double c;
	cout << "请输入两个值" << endl;
	while (cin >> a >> b) {
		try {
			if (a == -b) {
				throw "分母为零啦";       // 要在真正产生异常之前抛出，不然程序会终止掉
			}
			c = double(a * b / (a + b));
		}
		catch (const char* s) {
			cout << s << endl;
			cout << "请重新输入："<<endl;
			continue;
		}
		cout << c << endl;
	}
}

void d2test02() {
   /*
     无异常处理
   */
	cout << "异常处理" << endl;
	int a, b;
	double c;
	cout << "请输入两个值" << endl;
	while (cin >> a >> b) {
		cout << a << " " << b << endl;
		c = double(a * b / (a + b));   // 遇到分母为零的情况，程序抛出异常终止程序运行
		cout << c << endl;
	}
}
