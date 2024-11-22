#include<istream>
#include"student.h"
#include"book.h"
using namespace std;
void menu();

int main() {
	
	/*ͼ�����ϵͳ
	* ��ȡ�ļ� vector
	��¼ ѡ�������
	1��ע��ѧ��  2���鿴ѧ��  3��ɾ��ѧ���˻� 
	4������鱾��Ϣ 5���޸��鱾��Ϣ 6����ʾ�鱾��Ϣ
	7��ɾ���鱾��Ϣ   0���˳�*/
	Student stu;
	Book bo;
	vector<Student> vec;
	vec = stu.Read(vec);
	bool flag = stu.Login(vec);
	while (!flag) {					// ��¼ʧ��һֱ��ת����¼
		cout << "��¼ʧ�ܣ���ע���˻���" << endl;
		stu.Login(vec);
	}
	int choice;
	do{
		menu();
		// ����choice 
		cin >> choice;
		while (cin.get() != '\n')
			continue;
		switch (choice) {
		case 1:
			stu.SignUp();
			break;
		case 2:
			stu.Show();
			break;
		case 3:
			stu.Delete(vec);
			break;
		case 4:
			bo.Add_Book();
			break;
		case 5:
			bo.UpdateData();
			break;
		case 6:
			bo.Show();
			break;
		case 7:
			bo.DeleteBook();
			break;
		default:
			cout << "��������ȷ�ı�ţ�" << endl;
			break;
		}
	} while (choice);


	return 0;
}

void menu()
{
	cout << "+-----------------------------------------------+\n";
	cout << "|                  ͼ����Ϣ����ϵͳ             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1��ע��ѧ���˺�      |  5���޸�ͼ����Ϣ     |\n";
	cout << "|   2���鿴ѧ���˺�      |  6����ʾ�鱾��Ϣ     |\n";
	cout << "|   3��ɾ��ѧ���˺�      |  7��ɾ���鱾��Ϣ     |\n";
	cout << "|   4�����ͼ����Ϣ      |  0���˳�ϵͳ         |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     ��ѡ����Ҫִ�еĲ����������Ӧ��ţ���    |\n";
	cout << "+-----------------------------------------------+\n";
}