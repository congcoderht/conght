#include"Header.h"
using namespace std;
int main()
{
	int n = 0;int m = 0;int c = 0;int k = 0;
	int index = -1;
	int year = 0;
	namhoc newyear;
	hocsinh* S = NULL;
	Giaovien* T = NULL;
	Lophoc* C = NULL;
	Khoahoc* K = NULL;
	ReadStudent(S, n);
	ReadTeacher(T, m);
	/*PrintfStudent(S, n);
	PrintfTeacher(T, m);*/
	cout << CountCourse() << endl;
	system("pause");
	CreateClass(C, c);
	AddStuToClass(C, S, c, n);
	system("pause");
	//xuatGV(T, m);
	do {
		system("cls");
		string id, pass;
		login(id, pass);
		if (CheckPassIDStudent(S, id, pass, n, index))
		{
			cout << "           Dang nhap thanh cong" << endl;
			cout << " --------------------------------------" << endl;

			MenuStudent(S, C, index, n, c, id);
		}
		else
		{
			index = -1;
			cout << "Dang nhap sai,nhap lai!" << endl;
		}
	} while (index == -1);

	return 0;
}