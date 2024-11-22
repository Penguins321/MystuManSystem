#include<istream>
#include"student.h"
#include"book.h"
using namespace std;
void menu();

int main() {
	
	/*图书管理系统
	* 读取文件 vector
	登录 选择操作：
	1：注册学生  2：查看学生  3：删除学生账户 
	4：添加书本信息 5：修改书本信息 6：显示书本信息
	7：删除书本信息   0：退出*/
	Student stu;
	Book bo;
	vector<Student> vec;
	vec = stu.Read(vec);
	bool flag = stu.Login(vec);
	while (!flag) {					// 登录失败一直跳转到登录
		cout << "登录失败，请注册账户：" << endl;
		stu.Login(vec);
	}
	int choice;
	do{
		menu();
		// 重置choice 
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
			cout << "请输入正确的编号：" << endl;
			break;
		}
	} while (choice);


	return 0;
}

void menu()
{
	cout << "+-----------------------------------------------+\n";
	cout << "|                  图书信息管理系统             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1、注册学生账号      |  5、修改图书信息     |\n";
	cout << "|   2、查看学生账号      |  6、显示书本信息     |\n";
	cout << "|   3、删除学生账号      |  7、删除书本信息     |\n";
	cout << "|   4、添加图书信息      |  0、退出系统         |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     请选择你要执行的操作（输入对应编号）：    |\n";
	cout << "+-----------------------------------------------+\n";
}