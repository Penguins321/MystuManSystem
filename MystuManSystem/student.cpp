#include"student.h"
#include<fstream>
#include<iomanip>

//��ȡstudent�ļ����ڴ�
vector<Student>& Student::Read(vector<Student>& v) {
	fstream inFile;
	Student stu;
	inFile.open("student.txt");
	if (inFile.bad())
		cout << "�ļ���ȡʧ�ܣ�";
	while (inFile >> stu)
		v.push_back(stu);
	inFile.close();
	return v;
}

bool Student::Login(vector<Student>& vec) {
	string name;
	int password;
	int flag;				// �Ƿ��Ѿ����˺�
	bool f = false;			// ��¼�ɹ���־λ
	cout << "�Ƿ������˺� <1:��/0����> ��";
	while (!(cin >> flag) || (flag != 1 && flag != 0)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������Ч��������0��1��";
	}
	switch (flag)
	{
	case 1:
		cout << "�������û�����" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> password;
		// ����vector���������룬��ѯ�Ƿ���ƥ��
		for (Student stu : vec) {
			if (stu.name == name) {
				if (stu.password == password) {
					// �û������붼��ȷ
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
		// ע��student�û�
		SignUp();
		f = true;
		break;
	default:
		break;
	}
	return f;
}

// �û�ע��
void Student::SignUp() {
	Student stu;
	fstream outFile;
	cout << "������ע���û�����";
	cin >> stu.name;
	while (cin.get() != '\n')
		continue;
	cout << "������ע�����루���֣���";
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
	// ������ʾ
	for (Student s : vec) {
		//cout << "�û����� " << s.name << setw(16) <<  "���룺  " << s.password << endl;
		cout << left  << "�û�����" << s.name << right << setw(16) << "���룺 " << s.password << endl;
	}
	inFile.close();
}

void Student::Delete(vector<Student>& vec) {
	string name_del;
	cout << "�������㽫ɾ�����û����� ";
	cin >> name_del;
	// ������ɾ��Ԫ��
	for (auto it = vec.begin(); it != vec.end();) {
		if (it->name == name_del) {
			it = vec.erase(it);					// ������һ����Ч�ĵ�����
		}
		else {
			++it;
		}
	}
	// ɾ��Ԫ�غ�����ݴ���ļ�
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
		cout << name_del << " �û���ɾ��" << endl;
	}
	else {
		cout << "ֻʣ��ǰ�û���ɾ��ʧ�ܣ�" << endl;
	}
}

// ��������������
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
	cout << "�ֱ�����ѧ����������ѧ�ţ��ֻ��ţ�" << endl;
	cout << "����:" << endl;
	// ��ȡ����Ϣ�洢���ļ�
	fstream filein;
	filein.open("student.txt");
	cin >> name;
	filein << name << endl;
	cin.ignore();
	cout << "ѧ�ţ�" << endl;
	cin >> id;
	filein << id << endl;
	cin.ignore();
	cout << "�ֻ��ţ�" << endl;
	cin >> phone;
	filein << phone << endl;	
	filein.close();
}

// ����ѧ��ɾ��  --����ȡ���ڴ� ---�����ƥ��  -----����ȡ���������飬ѭ��ƥ�� --->ɾ�����ٴδ洢
void Student::Delete() {
	static const int SIZE = 10;
	Student* sp;
	sp = new Student[SIZE];

}
*/