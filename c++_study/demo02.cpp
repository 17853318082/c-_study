/*
  �쳣����
*/

#include<iostream>
#include<string>
using namespace std;
#ifdef DEBUG
void d2test01();
#endif // DEBUG


void d2test01() {
	/*
	  ���쳣����
	*/
	cout << "�쳣����" << endl;
	int a, b;
	double c;
	cout << "����������ֵ" << endl;
	while (cin >> a >> b) {
		try {
			if (a == -b) {
				throw "��ĸΪ����";       // Ҫ�����������쳣֮ǰ�׳�����Ȼ�������ֹ��
			}
			c = double(a * b / (a + b));
		}
		catch (const char* s) {
			cout << s << endl;
			cout << "���������룺"<<endl;
			continue;
		}
		cout << c << endl;
	}
}

void d2test02() {
   /*
     ���쳣����
   */
	cout << "�쳣����" << endl;
	int a, b;
	double c;
	cout << "����������ֵ" << endl;
	while (cin >> a >> b) {
		cout << a << " " << b << endl;
		c = double(a * b / (a + b));   // ������ĸΪ�������������׳��쳣��ֹ��������
		cout << c << endl;
	}
}
