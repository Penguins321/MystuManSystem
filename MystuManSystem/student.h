#pragma once
#ifndef __STUDENT__
#define __STUDENT__
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Student {
private:
	string name;    // 学生用户名
	int password;	// 密码
public:
	Student(){}
	Student(const string& s, int p):name(s),password(p){}
	virtual ~Student(){} 

	// 学生信息从文件读取到内存,vector存储
	vector<Student>& Read(vector<Student>& v);
	bool Login(vector<Student>& v);					// 登录
	void SignUp();									// 用户注册
	void Show() const;									// 查询
	void Delete(vector<Student>& vec);				// 根据用户名删除

	// 重载输入输出流istream
	friend istream& operator>>(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, Student& stu);
};

#endif