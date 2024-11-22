#pragma once
#ifndef __STUDENT__
#define __STUDENT__
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Student {
private:
	string name;    // ѧ���û���
	int password;	// ����
public:
	Student(){}
	Student(const string& s, int p):name(s),password(p){}
	virtual ~Student(){} 

	// ѧ����Ϣ���ļ���ȡ���ڴ�,vector�洢
	vector<Student>& Read(vector<Student>& v);
	bool Login(vector<Student>& v);					// ��¼
	void SignUp();									// �û�ע��
	void Show() const;									// ��ѯ
	void Delete(vector<Student>& vec);				// �����û���ɾ��

	// �������������istream
	friend istream& operator>>(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, Student& stu);
};

#endif