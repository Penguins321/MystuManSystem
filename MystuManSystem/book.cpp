#include<iostream>
#include<iomanip>
#include"book.h"
using namespace std;

void Book::Add_Book() {
	Book bo;
	cout << "请输入书籍名称: ";
	getline(cin, bo.book_name);
	cout << "请输入书籍号：" << endl;
	cin >> bo.book_id;
	// 保存到文件
	fstream outFile;
	outFile.open("book.txt",std::ios::app);					//默认输出到文件是覆盖，ios::app为追加内容
	outFile << bo;
	cout << "书籍添加成功!" << endl;
	outFile.close();
}

void Book::SaveFile(vector<Book> vec) {

	Book bo;
	fstream outFile;
	outFile.open("book.txt", std::ios::app);					
	while (vec.size()) {
		bo = vec.back();
		outFile << bo;
		vec.pop_back();
	}
	outFile.close();
}


// 保存函数重载  保存时清空原来的文件数据
void Book::SaveFile(vector<Book> vec,int m) {

	Book bo;
	fstream outFile;
	outFile.open("book.txt",ios::out|ios::trunc);
	while (vec.size()) {
		bo = vec.back();
		outFile << bo;
		vec.pop_back();
	}
	outFile.close();
}

void Book::UpdateData() {
	int book_id;
	cout << "请输入你想要修改的书籍号：";
	cin >> book_id;
	// 读取文件
	vector<Book> vec;
	Book bo;
	fstream inFile;
	inFile.open("book.txt");
	while (inFile >> bo) {
		vec.push_back(bo);
	}
	// 遍历指定数据
	if (vec.size()) {
		for (auto it = vec.begin(); it != vec.end();++it) {
			if (it->book_id == book_id) {
				cout << "请输入修改后的书籍名称：" << endl;
				string book_name;
				cin >> book_name;
				it->book_name = book_name;
			}
		}
	}
	inFile.close();
	SaveFile(vec,1);
	cout << "书籍信息修改成功" << endl;
}

void Book::Show() const {
	vector<Book> vec;
	Book bo;
	fstream inFile;
	inFile.open("book.txt");
	while (inFile >> bo) {
		vec.push_back(bo);
	}
	/*
	C++ primer plus 书籍名称包含空格时会出现问题*/

	// 遍历数据，展示
	if (vec.size()) {
		cout << left << setw(16) << "书籍号 " << left << setw(16) << "图书名称" << endl;
		cout << string(35, '-') << endl; 
		for (Book book : vec) {
			// cout << "书籍号： " << book.book_id << set << "书籍： " << book.book_name << endl;
			cout << left << setw(16) << book.book_id << left << setw(16) << book.book_name << endl;

		}
	}
	inFile.close();
	
}

void Book::DeleteBook() {
	int book_id;
	cout << "请输入你想要删除的书籍号：";
	cin >> book_id;
	// 读取文件
	vector<Book> vec;
	Book bo;
	fstream inFile;
	inFile.open("book.txt");
	while (inFile >> bo) {
		vec.push_back(bo);
	}
	// 遍历删除指定数据
	if (vec.size()) {
		for (auto it = vec.begin(); it != vec.end();) {
			if (it->book_id == book_id) {
				it = vec.erase(it);
			}
			else
				++it;
		}
	}
	inFile.close();
	SaveFile(vec,1);
	cout << "编号： " << book_id << " 对应的书籍已经删除" << endl;
}


ostream& operator<<(ostream& os, const Book& bo) {
	os << bo.book_name << '\n' << bo.book_id << '\n';
	return os;
}

istream& operator>>(istream& is,Book& bo) {
	// is >> bo.book_name >> bo.book_id;
	getline(is, bo.book_name);
	is >> bo.book_id;
	is.ignore(1000, '\n');
	return is;
}