#include"Header.h"
int CountStudent()
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
int CountTeacher()
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
void ReadStudent(hocsinh*& S, int& n)
{
	ifstream f;
	S = new hocsinh[CountStudent()];
	f.open("Text.csv");
	if (!f.is_open())
	{
		cout << "Mo file that bai" << endl;
		return;
	}
	int i = 0;
	string line;
	getline(f, line);//Doc dong dau vao bien tam
	while (!f.eof())
	{
		getline(f, S[i].ID, ',');
		getline(f, S[i].ho, ',');
		getline(f, S[i].ten, ',');
		getline(f, S[i].Lop, ',');
		getline(f, S[i].Khoa, ',');
		getline(f, S[i].gioitinh, ',');
		getline(f, S[i].ngaysinh, ',');
		getline(f, S[i].IdXaHoi, ',');
		getline(f, S[i].matkhau);
		i++;
	}
	f.close();
	n = i - 1;
}
void ReadTeacher(Giaovien*& T, int& m)
{
	ifstream f;
	T = new Giaovien[CountTeacher()];
	f.open("Giaovien.csv");
	if (!f.is_open())
	{
		cout << "Mo file that bai" << endl;
		return;
	}
	int i = 0;
	string l;
	getline(f, l);
	while (!f.eof())
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
void Printf1Student(hocsinh S)
{
	cout << "ID " << S.ID << endl;
	cout << "Ho ten " << S.ho << " " << S.ten << endl;
	cout << "Lop " << S.Lop << endl;
	cout << "Khoa " << S.Khoa << endl;
	cout << "Gioi tinh " << S.gioitinh << endl;
	cout << "Ngay sinh " << S.ngaysinh << endl;
	cout << "IDXH " << S.IdXaHoi << endl;
	cout << "Mat khau " << S.matkhau << endl;
}
void PrintfStudent(hocsinh* S, int n)
{
	for (int i = 0;i < n; i++)
	{
		cout << "Hoc Sinh " << i + 1 << " ID " << S[i].ID << " Ho ten " << S[i].ho << " " << S[i].ten << "Lop " << S[i].Lop << " Khoa " << S[i].Khoa << " Gioi tinh " << S[i].gioitinh << " Ngay sinh " << S[i].ngaysinh << " IDXH " << S[i].IdXaHoi << " Mat khau " << S[i].matkhau << endl;
	}
}
void Printf1Teacher(Giaovien T, int m)
{
	cout << "ID " << T.id << endl;
	cout << "Ho ten " << T.ho << " " << T.ten << endl;
	cout << "Gioi tinh " << T.gioitinh << endl;
	cout << "Ngay sinh " << T.ngaysinh << endl;
	cout << "IDXH " << T.IDXH << endl;
	cout << "Mat khau " << T.matkhau << endl;
}
void PrintfTeacher(Giaovien* T, int m)
{
	for (int i = 0;i < m; i++)
	{
		cout << "Giao Vien " << i + 1 << " ID " << T[i].id << " Ho ten " << T[i].ho << " " << T[i].ten << " Gioi tinh " << T[i].gioitinh << " Ngay sinh " << T[i].ngaysinh << " IDXH " << T[i].IDXH << " Mat khau " << T[i].matkhau << endl;
	}
}
bool CheckPassIDStudent(hocsinh* S, string id, string pass, int n, int& index)
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
bool CheckPassIDTeacher(Giaovien* T, string id, string pass, int m, int& index2)
{
	for (int i = 0;i < m;i++)
	{
		if (id == T[i].id && pass == T[i].matkhau)
		{
			index2 = i;
			return true;
		}
	}
	return false;
}
void login(string& id, string& pass)
{
	cout << "==================================================================\n";
	cout << "|<<<<<<<<<<<<<<<<   LEARNING MANAGEMENT SYSTEM   >>>>>>>>>>>>>>>>|\n";
	cout << "|----------------------------------------------------------------|\n";
	cout << "|----------------      [login your account]      ----------------|\n\n";
	cout << "_________________________________________________________________\n";
	cout << "|[ID]: ";
	getline(cin, id);
	cout << "|[Password]: ";
	getline(cin, pass);
}
void MenuStudent(hocsinh* S, int& index, int n, string id)
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
			Printf1Student(S[index]);
			system("pause");
		}
		if (k == 2)
		{
			cout << "Doi mat khau" << endl;
			ChangepassStudent(S, n, id);
			UpdatefileStudent(S, n);
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

void ChangepassStudent(hocsinh*& S, int n, string id)
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
void UpdatefileStudent(hocsinh*& S, int n)
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
void CreateNewStudyYear(namhoc& newyear)
{
	cout << "Nhap nam hoc ban tao moi: ";cin >> newyear.Nienkhoa;
	newyear.khoa = NULL;
	newyear.lop = NULL;
	cout << "Ban da tao thanh cong nam hoc " << newyear.Nienkhoa << " - " << newyear.Nienkhoa + 1 << endl;
}
