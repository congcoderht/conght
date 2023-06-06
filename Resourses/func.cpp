#include"Header.h"
int demHocsinh()
{
	int dem = 0;
	ifstream f;
	f.open("Text.csv");
	if (!f.is_open())
	{
		return 0;
	}
	string line;
	while (f)
	{
		dem++;
		getline(f, line);
	}
	f.close();
	return dem - 1;
}
int demgiaovien()
{
	int dem = 0;
	ifstream f;
	f.open("Giaovien.csv");
	if (!f.is_open())
	{
		return 0;
	}
	string line;
	while (f)
	{
		dem++;
		getline(f, line);
	}
	f.close();
	return dem - 1;
}
void Docfilehs(hocsinh*& S, int& n)
{
	ifstream f;
	S = new hocsinh[demHocsinh()];
	f.open("Text.csv");
	if (!f.is_open())
	{
		cout << "Mo file that bai" << endl;
		return;
	}
	int i = 0;
	string line;
	getline(f, line);
	while (f)
	{
		getline(f, S[i].ID, ',');
		getline(f, S[i].ho, ',');
		getline(f, S[i].ten, ',');
		getline(f, S[i].gioitinh, ',');
		getline(f, S[i].ngaysinh, ',');
		getline(f, S[i].IdXaHoi, ',');
		getline(f, S[i].matkhau);
		i++;
	}
	f.close();
	n = i - 1;
}
void Docfilegv(Giaovien*& T, int& m)
{
	ifstream f;
	T = new Giaovien[demgiaovien()];
	f.open("Giaovien.csv");
	if (!f.is_open())
	{
		cout << "Mo file that bai" << endl;
		return;
	}
	int i = 0;
	string l;
	getline(f, l);
	while (f)
	{
		getline(f, T[i].id, ',');
		getline(f, T[i].ho, ',');
		getline(f, T[i].ten, ',');
		getline(f, T[i].gioitinh, ',');
		getline(f, T[i].ngaysinh, ',');
		getline(f, T[i].IDXH, ',');
		getline(f, T[i].matkhau);
		i++;
	}
	f.close();
	m = i - 1;
}
void xuat1hs(hocsinh S)
{
	cout << "ID " << S.ID << endl;
	cout << "Ho ten " << S.ho << " " << S.ten << endl;
	cout << "Gioi tinh " << S.gioitinh << endl;
	cout << "Ngay sinh " << S.ngaysinh << endl;
	cout << "IDXH " << S.IdXaHoi << endl;
	cout << "Mat khau " << S.matkhau << endl;
}
void xuatHS(hocsinh* S, int n)
{
	for (int i = 0;i < n; i++)
	{
		cout << "Hoc Sinh " << i + 1 << " ID " << S[i].ID << " Ho ten " << S[i].ho << " " << S[i].ten << " Gioi tinh " << S[i].gioitinh << " Ngay sinh " << S[i].ngaysinh << " IDXH " << S[i].IdXaHoi << " Mat khau " << S[i].matkhau << endl;
	}
}
void xuatGV(Giaovien* T, int m)
{
	for (int i = 0;i < m;i++)
	{
		cout << "Giao vien " << i + 1 << " ID " << T[i].id << " HO ten " << T[i].ho << " " << T[i].ten << " Gioi Tinh " << T[i].gioitinh << " Ngay sinh " << T[i].ngaysinh << " ID xahoi " << T[i].IDXH << " Mat khau " << T[i].matkhau << endl;
	}
}
bool checkPassIDhs(hocsinh* S, string id, string pass, int n, int& index)
{
	for (int i = 0;i < n;i++)
	{
		if (id == S[i].ID && pass == S[i].matkhau)
		{
			index = i;
			return true;
		}
	}
	return false;
}
void login(string& id, string& pass)
{
	cout << "Nhap id:";
	getline(cin, id);
	cout << "Nhap mat khau:";
	getline(cin, pass);
}
void MenuHS(hocsinh* S, int& index, int n, string id)
{
	int k = 0;
	do {
		system("cls");
		cout << "--------------------------- " << endl;
		cout << "1.Xem thong tin ca nhan" << endl;
		cout << "2.Thay doi mat khau dang nhap" << endl;
		cout << "3.Trang chu he thong" << endl;
		cout << "0.Dang xuat" << endl;
		cout << "--------------------------" << endl;
		cout << "Nhap lua chon: ";cin >> k;
		if (k == 1)
		{
			xuat1hs(S[index]);
			system("pause");
		}
		if (k == 2)
		{
			cout << "Doi mat khau" << endl;
			changepasshs(S, n, id);
			capnhatfilehs(S, n);
			system("pause");
		}
		if (k == 0)
		{
			cout << "Ban muon dang xuat?" << endl;
			cout << "0.Dong Y     1.Huy" << endl;
			index = -1;
			cin >> k;
			system("pause");
		}
	} while (k != 0);
}
void changepasshs(hocsinh*& S, int n, string id)
{
	string temp;
	cout << "Nhap mat khau cu:";
	cin.ignore();
	getline(cin, temp);
	for (int i = 0;i < n;i++)
	{
		if (S[i].ID == id)
		{
			if (temp == S[i].matkhau)
			{
				cout << "Nhap mat khau moi:";
				getline(cin, temp);
				S[i].matkhau = temp;
				cout << "Doi mat khau thanh cong" << endl;
			}
			else
			{
				cout << "Mat khau sai" << endl;
			}
		}
	}

}
void capnhatfilehs(hocsinh*& S, int n)
{
	fstream f1;
	f1.open("Text.csv");
	if (!f1.is_open())
	{
		cout << "Mo file that bai" << endl;
	}
	else
	{
		f1 << "ID" << "," << "Ho" << "," << "Ten" << "," << "Gioi tinh" << "," << "Ngay sinh" << "," << "Id xa hoi" << "," << "Mat khau" << endl;
		for (int i = 0;i < n;i++)
		{
			f1 << S[i].ID << "," << S[i].ho << "," << S[i].ten << "," << S[i].gioitinh << "," << S[i].ngaysinh << "," << S[i].IdXaHoi << "," << S[i].matkhau << endl;
		}
	}
	f1.close();
}
void taonamhoc(int& newyear)
{
	cout << "Ban nhap nam hoc can tao: ";cin >> newyear;
	cout << "Ban da tao nam hoc moi " << newyear << "-" << newyear + 1 << endl;
	fstream f;
	f.open("Namhocmoi.csv", ios::out | ios::trunc);
	if (!f.is_open())
		cout << "mo file that bai" << endl;
	else
	{
		f << "Nam hoc " << newyear << "-" << newyear + 1 << endl;
		f << "\"Day la nam hoc moi nen o day se chua thong tin cua sinh vien nam nhat\"" << endl;
	}
	f.close();
}

