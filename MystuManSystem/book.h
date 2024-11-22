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
	string book_name;					// 书名
	int book_id;						// 图书编号
public:
	Book(){}
	Book(const string& s,int id):book_name(s),book_id(id){}
	virtual~Book(){}

	void Add_Book();									// 添加图书
	void SaveFile(vector<Book> vec);					// 保存图书文件
	void SaveFile(vector<Book> vec, int m);				// 重载保存图书文件函数，此为覆盖保存
	void UpdateData();									// 修改书籍信息
	void Show() const;									// 展示书籍
	void DeleteBook();									// 删除书籍

	// 重载输入输出运算符
	friend ostream& operator<<(ostream& os, const Book& bo);
	friend istream& operator>>(istream& is,Book& bo);

};
#endif // !__BOOK__
