#include"Header.h"
using namespace std;
int main()
{
	int n = 0;int m = 0;
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
			MenuStudent(S, index, n, id);
		}
		else
		{
			index = -1;
			cout << "dang nhap sai" << endl;
		}
	} while (index == -1);

	//	cout << "Doi mat khau" << endl;
		//changepasshs(S, n, id);
		//capnhatfilehs(S, n);
		//taonamhoc(year);
	return 0;
}