/*
   c++ �ļ�����
   fstream �ļ��������������
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

/*
  �ļ�д�����
*/
void d4test01() {
	// ���ļ���д��һ���ļ�
	ofstream fout;    // ����һ���ļ����������,������������ļ�
	fout.open("test/test.txt");   // ���ļ�, ���ܴ򿪲����ڵ��ļ������ļ�������ʱ�������Զ�����
	if (fout.is_open()) {
		cout << "�ļ��Ѵ򿪣�����в�����" << endl;
	}
	else {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	string buff;      // ����һ�����뻺������Ҳ����ֱ�����룬���û�����
	cout << "����д���ļ�" << endl;
	// ���ļ���д��ʮ������     ��ԭ�е����ݽ��и���            
	for (int i = 0; i < 10; i++) {
		buff = "���ǵڣ�" + to_string(i); +"��";   // ���������ֽ����ַ���ƴ�ӣ���intתΪstring
		cout << "����д��:" << buff << endl;
		fout << buff;
		fout << "\n";    // ��βд�뻻�з�
		buff.clear();
	}
	fout.close();
	fout.open("test/test.txt", ios_base::app);  // ���ļ���׷��
	// ���ļ���׷��
	for (int i = 0; i < 10; i++) {
		buff = "���ǵڣ�" + to_string(i)+"��";
		cout << "����д��:" << buff << endl;
		fout << buff;
		fout << "\n";    // ��βд�뻻�з�
		buff.clear();
	}
	cout << "������д���ļ���" << endl;
	fout.close();
	cout << "�ļ��ѹر�!" << endl;
}

/*
  �ļ���ȡ����
*/
void d4test02() {
	ifstream fin;   // ����һ���ļ�����������
	fin.open("test/test.txt");  // ���ļ�
	// �ж��ļ��Ƿ��
	if (fin.is_open()) {
		cout << "�ļ��Ѵ�����ж�ȡ��" << endl;
	} else{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	// ���ļ��ж�ȡ����
	string buff;              // ������ȡ������ char buff[1024]����Ҳ����
	// ��ȡ�����ַ�
	string c;
	fin >> c;                                 // �����ո���߷���ʱֹͣ��ȡ
	cout << "��ȡ�����ַ���" << c << endl; 

	char line[128];
	buff.clear();
	// ��ȡһ��  ���ɹ���ȡһ��ʱ��ָ��������һ��
	fin.getline(line,128);                       // ���� \nʱֹͣ��ȡ
	cout << "��һ������char[]��" << line << endl;  
	getline(fin, buff);         // ��ȡһ������       ����\nֹͣ��ȡ
	cout << "��һ������string��" << buff << endl;      
	
	string content;
	// ��ȡ�ļ���ȫ������
	// ����һ��
	fin.close();
	fin.open("test/test.txt");       // ���´��ļ���ָ�������ļ��ײ�
	std::ostringstream tmp;     // ͷ�ļ� sstream,����һ���ַ���������
	tmp << fin.rdbuf();          // ���ļ�������д�뻺����
	content = tmp.str();
	cout << "�ļ���ȫ�����ݣ�����1����" << endl;
	cout<< content << endl;

	// ��������
	fin.close();
	fin.open("test/test.txt");
	istreambuf_iterator<char> begin(fin);    // ��������������������������������������ָ���ļ�ͷ��ָ�룩
	istreambuf_iterator<char> end;              // ����������
	string content2(begin,end);       // ���ƹ��죬�����ݸ�string
	cout << "�ļ���ȫ�����ݣ�����2����" << endl;
	cout << content2 << endl;
	fin.close();
	cout << "�ļ��ѹر�! " << endl;

}


int main() {
	d4test01();
	d4test02();
	cout << "123" << endl;

	return 0;
}