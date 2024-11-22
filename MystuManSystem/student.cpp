#include"student.h"
#include<fstream>
#include<iomanip>

//读取student文件到内存
vector<Student>& Student::Read(vector<Student>& v) {
	fstream inFile;
	Student stu;
	inFile.open("student.txt");
	if (inFile.bad())
		cout << "文件读取失败！";
	while (inFile >> stu)
		v.push_back(stu);
	inFile.close();
	return v;
}

bool Student::Login(vector<Student>& vec) {
	string name;
	int password;
	int flag;				// 是否已经有账号
	bool f = false;			// 登录成功标志位
	cout << "是否已有账号 <1:有/0：无> ：";
	while (!(cin >> flag) || (flag != 1 && flag != 0)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "输入无效，请输入0或1：";
	}
	switch (flag)
	{
	case 1:
		cout << "请输入用户名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> password;
		// 迭代vector容器里密码，查询是否有匹配
		for (Student stu : vec) {
			if (stu.name == name) {
				if (stu.password == password) {
					// 用户名密码都正确
					f = true;
					break;
				}
				else
					continue;
			}
			else
				continue;
		}
		break;
	case 0:
		// 注册student用户
		SignUp();
		f = true;
		break;
	default:
		break;
	}
	return f;
}

// 用户注册
void Student::SignUp() {
	Student stu;
	fstream outFile;
	cout << "请输入注册用户名：";
	cin >> stu.name;
	while (cin.get() != '\n')
		continue;
	cout << "请输入注册密码（数字）：";
	cin >> stu.password;
	outFile.open("student.txt",ios::app);
	outFile << stu;
	outFile.close();
}

void Student::Show() const {
	fstream inFile;
	Student stu;
	vector<Student> vec;
	inFile.open("student.txt");
	while (inFile >> stu) {
		vec.push_back(stu);
	}
	// 遍历显示
	for (Student s : vec) {
		//cout << "用户名： " << s.name << setw(16) <<  "密码：  " << s.password << endl;
		cout << left  << "用户名：" << s.name << right << setw(16) << "密码： " << s.password << endl;
	}
	inFile.close();
}

void Student::Delete(vector<Student>& vec) {
	string name_del;
	cout << "请输入你将删除的用户名： ";
	cin >> name_del;
	// 迭代器删除元素
	for (auto it = vec.begin(); it != vec.end();) {
		if (it->name == name_del) {
			it = vec.erase(it);					// 返回下一个有效的迭代器
		}
		else {
			++it;
		}
	}
	// 删除元素后把数据存回文件
	if (vec.size() > 0) {
		fstream outFile;
		outFile.open("student.txt",ios::out|ios::trunc);
		Student stu;
		while (vec.size() > 0) {
			stu = vec.back();
			outFile << stu;
			vec.pop_back();
		}
		outFile.close();
		cout << name_del << " 用户已删除" << endl;
	}
	else {
		cout << "只剩当前用户，删除失败！" << endl;
	}
}

// 重载输入流对象
istream& operator>>( istream& is, Student& stu) {
	is >> stu.name >> stu.password;
	return is;
}

ostream& operator<<( ostream& os, Student& stu) {
	os << stu.name << '\n' << stu.password << '\n';
	return os;
}




/*
Student::Student(const string& s, long n, int p) {
	name = s;
	id = n;
	phone = p;
}

void Student::Add() {
	cout << "分别输入学生的姓名，学号，手机号：" << endl;
	cout << "姓名:" << endl;
	// 获取的信息存储到文件
	fstream filein;
	filein.open("student.txt");
	cin >> name;
	filein << name << endl;
	cin.ignore();
	cout << "学号：" << endl;
	cin >> id;
	filein << id << endl;
	cin.ignore();
	cout << "手机号：" << endl;
	cin >> phone;
	filein << phone << endl;	
	filein.close();
}

// 根据学号删除  --》读取到内存 ---》如何匹配  -----》读取到对象数组，循环匹配 --->删除后再次存储
void Student::Delete() {
	static const int SIZE = 10;
	Student* sp;
	sp = new Student[SIZE];

}
*/