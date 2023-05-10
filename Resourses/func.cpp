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
	return dem-1;
}
void Docfilehs(hocsinh*& S,int &n)
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
	getline(f,line);
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
void xuat1hs(hocsinh* S, string id, int n)
{
	for (int i = 0;i < n;i++)
	{
		if (id == S[i].ID)
		{
			cout << "ID " << S[i].ID << endl;
			cout << "Ho ten " << S[i].ho << " " << S[i].ten << endl;
			cout << "Gioi tinh " << S[i].gioitinh << endl;
			cout << "Ngay sinh " << S[i].ngaysinh << endl;
			cout << "IDXH " << S[i].IdXaHoi << endl;
			break;
		}
	}
}
void xuatHS(hocsinh* S,int n)
{
	for (int i = 0;i < n; i++)
	{
		cout << "Hoc Sinh " << i + 1 << " ID " << S[i].ID << " Ho ten " << S[i].ho << " " << S[i].ten << " Gioi tinh " << S[i].gioitinh << " Ngay sinh " << S[i].ngaysinh << " IDXH " << S[i].IdXaHoi << " Mat khau " << S[i].matkhau << endl;
	}
}
bool checkPassIDhs(hocsinh* S, string id, string pass, int n, int& index)
{
	for (int i = 0;i < n;i++)
	{
		index = i;
		if (id == S[i].ID && pass == S[i].matkhau)
			return true;
	}
	return false;
}
void login(string& id, string& pass)
{
	cout << "Nhap id:";
	//cin.ignore();
	getline(cin, id);
	cout << "Nhap mat khau:";
	getline(cin,pass);
}
void changepasshs(hocsinh*& S, int n, string id)
{
	string temp;
	cout << "Nhap mat khau cu:";
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
	cout << "Ban da tao nam hoc moi " << newyear << "-"<<newyear + 1 << endl;
	fstream f;
	f.open("Namhocmoi.csv",ios::out|ios::trunc);
	if (!f.is_open())
		cout << "mo file that bai" << endl;
	else
	{
		f << "Nam hoc " << newyear << "-" << newyear + 1 << endl;
		f << "\"Day la nam hoc moi nen o day se chua thong tin cua sinh vien nam nhat\"" << endl;
	}
	f.close();
}