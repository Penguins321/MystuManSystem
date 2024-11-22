#pragma once
#ifndef __BOOK__
#define __BOOK__
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Book {
private:
	string book_name;					// ����
	int book_id;						// ͼ����
public:
	Book(){}
	Book(const string& s,int id):book_name(s),book_id(id){}
	virtual~Book(){}

	void Add_Book();									// ���ͼ��
	void SaveFile(vector<Book> vec);					// ����ͼ���ļ�
	void SaveFile(vector<Book> vec, int m);				// ���ر���ͼ���ļ���������Ϊ���Ǳ���
	void UpdateData();									// �޸��鼮��Ϣ
	void Show() const;									// չʾ�鼮
	void DeleteBook();									// ɾ���鼮

	// ����������������
	friend ostream& operator<<(ostream& os, const Book& bo);
	friend istream& operator>>(istream& is,Book& bo);

};
#endif // !__BOOK__
