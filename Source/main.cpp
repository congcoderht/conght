#include"Header.h"
using namespace std;
int main()
{
	int n = 0;
	int index = 0;
	int year = 0;
	hocsinh* S;
	Docfilehs(S, n);
	cout << "----------Dang Nhap-------------" << endl;
	string id, pass;
	login(id, pass);
	if (checkPassIDhs(S, id, pass, n,index))
		cout << "Dang nhap thanh cong" << endl;
	else
		cout << "dang nhap sai" << endl;
	cout << "Doi mat khau" << endl;
	changepasshs(S, n, id);
	capnhatfilehs(S, n);
	taonamhoc(year);
	return 0;
}