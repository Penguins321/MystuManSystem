#include<iostream>
#include<iomanip>
#include"book.h"
using namespace std;

void Book::Add_Book() {
	Book bo;
	cout << "�������鼮����: ";
	getline(cin, bo.book_name);
	cout << "�������鼮�ţ�" << endl;
	cin >> bo.book_id;
	// ���浽�ļ�
	fstream outFile;
	outFile.open("book.txt",std::ios::app);					//Ĭ��������ļ��Ǹ��ǣ�ios::appΪ׷������
	outFile << bo;
	cout << "�鼮��ӳɹ�!" << endl;
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


// ���溯������  ����ʱ���ԭ�����ļ�����
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
	cout << "����������Ҫ�޸ĵ��鼮�ţ�";
	cin >> book_id;
	// ��ȡ�ļ�
	vector<Book> vec;
	Book bo;
	fstream inFile;
	inFile.open("book.txt");
	while (inFile >> bo) {
		vec.push_back(bo);
	}
	// ����ָ������
	if (vec.size()) {
		for (auto it = vec.begin(); it != vec.end();++it) {
			if (it->book_id == book_id) {
				cout << "�������޸ĺ���鼮���ƣ�" << endl;
				string book_name;
				cin >> book_name;
				it->book_name = book_name;
			}
		}
	}
	inFile.close();
	SaveFile(vec,1);
	cout << "�鼮��Ϣ�޸ĳɹ�" << endl;
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
	C++ primer plus �鼮���ư����ո�ʱ���������*/

	// �������ݣ�չʾ
	if (vec.size()) {
		cout << left << setw(16) << "�鼮�� " << left << setw(16) << "ͼ������" << endl;
		cout << string(35, '-') << endl; 
		for (Book book : vec) {
			// cout << "�鼮�ţ� " << book.book_id << set << "�鼮�� " << book.book_name << endl;
			cout << left << setw(16) << book.book_id << left << setw(16) << book.book_name << endl;

		}
	}
	inFile.close();
	
}

void Book::DeleteBook() {
	int book_id;
	cout << "����������Ҫɾ�����鼮�ţ�";
	cin >> book_id;
	// ��ȡ�ļ�
	vector<Book> vec;
	Book bo;
	fstream inFile;
	inFile.open("book.txt");
	while (inFile >> bo) {
		vec.push_back(bo);
	}
	// ����ɾ��ָ������
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
	cout << "��ţ� " << book_id << " ��Ӧ���鼮�Ѿ�ɾ��" << endl;
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