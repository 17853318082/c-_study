/*
   c++ 文件操作
   fstream 文件输入输出流操作
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

/*
  文件写入操作
*/
void d4test01() {
	// 向文件中写入一个文件
	ofstream fout;    // 创建一个文件输出流对象,将内容输出到文件
	fout.open("test/test.txt");   // 打开文件, 不能打开不存在的文件，当文件不存在时，不会自动创建
	if (fout.is_open()) {
		cout << "文件已打开，请进行操作：" << endl;
	}
	else {
		cout << "文件打开失败！" << endl;
		return;
	}
	string buff;      // 创建一个输入缓冲区，也可以直接输入，不用缓冲区
	cout << "正在写入文件" << endl;
	// 向文件中写入十行数据     对原有的数据进行覆盖            
	for (int i = 0; i < 10; i++) {
		buff = "这是第：" + to_string(i); +"行";   // 用于与数字进行字符串拼接，将int转为string
		cout << "正在写入:" << buff << endl;
		fout << buff;
		fout << "\n";    // 结尾写入换行符
		buff.clear();
	}
	fout.close();
	fout.open("test/test.txt", ios_base::app);  // 在文件后追加
	// 在文件后追加
	for (int i = 0; i < 10; i++) {
		buff = "这是第：" + to_string(i)+"行";
		cout << "正在写入:" << buff << endl;
		fout << buff;
		fout << "\n";    // 结尾写入换行符
		buff.clear();
	}
	cout << "内容已写入文件！" << endl;
	fout.close();
	cout << "文件已关闭!" << endl;
}

/*
  文件读取操作
*/
void d4test02() {
	ifstream fin;   // 创建一个文件输入流对象
	fin.open("test/test.txt");  // 打开文件
	// 判断文件是否打开
	if (fin.is_open()) {
		cout << "文件已打开请进行读取：" << endl;
	} else{
		cout << "文件打开失败！" << endl;
		return;
	}
	// 从文件中读取数据
	string buff;              // 创建读取缓冲区 char buff[1024]数组也可以
	// 读取单个字符
	string c;
	fin >> c;                                 // 遇到空格或者分行时停止读取
	cout << "读取单个字符：" << c << endl; 

	char line[128];
	buff.clear();
	// 读取一行  当成功读取一行时，指针跳入下一行
	fin.getline(line,128);                       // 遇到 \n时停止读取
	cout << "读一行数据char[]：" << line << endl;  
	getline(fin, buff);         // 读取一行数据       遇到\n停止读取
	cout << "读一行数据string：" << buff << endl;      
	
	string content;
	// 读取文件的全部内容
	// 方法一：
	fin.close();
	fin.open("test/test.txt");       // 重新打开文件，指针跳到文件首部
	std::ostringstream tmp;     // 头文件 sstream,创建一个字符流缓冲区
	tmp << fin.rdbuf();          // 将文件的内容写入缓冲区
	content = tmp.str();
	cout << "文件的全部内容（方法1）：" << endl;
	cout<< content << endl;

	// 方法二：
	fin.close();
	fin.open("test/test.txt");
	istreambuf_iterator<char> begin(fin);    // 将对象传入输入流缓冲区迭代器（迭代器生成指向文件头的指针）
	istreambuf_iterator<char> end;              // 结束迭代器
	string content2(begin,end);       // 复制构造，将内容给string
	cout << "文件的全部内容（方法2）：" << endl;
	cout << content2 << endl;
	fin.close();
	cout << "文件已关闭! " << endl;

}


int main() {
	d4test01();
	d4test02();
	cout << "123" << endl;

	return 0;
}