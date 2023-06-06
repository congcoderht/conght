#include"Header.h"
using namespace std;
int main()
{
	int n = 0;
	int index = -1;
	int year = 0;
	hocsinh* S;
	Giaovien* T;
	int m = 0;
	Docfilehs(S, n);
	Docfilegv(T, m);
	//xuatHS(S, n);
	//xuatGV(T, m);
	do {
		system("cls");
		cout << "----------Dang Nhap-------------" << endl;
		string id, pass;
		login(id, pass);
		if (checkPassIDhs(S, id, pass, n, index))
		{
			cout << "Dang nhap thanh cong" << endl;
			cout << " --------------------------------------" << endl;
			MenuHS(S, index, n, id);
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