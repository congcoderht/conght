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
void MenuStudent(hocsinh* S, Lophoc* C, int& index, int n, int c, string id)
{
	int k = 0;
	do {
		system("cls");
		cout << "==================================================================\n";
		cout << "|<<<<<<<<<<<<<<<<   LEARNING MANAGEMENT SYSTEM   >>>>>>>>>>>>>>>>|\n";
		cout << "|----------------------------------------------------------------|\n";
		cout << "|----------------           MENU STUDENT         ----------------|\n\n";
		cout << "_________________________________________________________________\n";
		cout << "+****************************************************************+" << endl;
		cout << "*                                                                *" << endl;
		cout << "*          1.Xem thong tin ca nhan                               *" << endl;
		cout << "*          2.Thay doi mat khau dang nhap                         *" << endl;
		cout << "*          3.Xem danh sach cac lop                               *" << endl;
		cout << "*          4.Xem danh sach cac hoc sinh trong lop                *" << endl;
		cout << "*          5.Xem danh sach cac khoa hoc cua minh                 *" << endl;
		cout << "*          6.Xem bang diem cua minh                              *" << endl;
		cout << "*          7.Tro lai menu he thong                               *" << endl;
		cout << "*          0.Dang xuat                                           *" << endl;
		cout << "*                                                                *" << endl;
		cout << "+****************************************************************+" << endl;
		cout << "Nhap lua chon: ";cin >> k;
		switch (k) {
		case 1:
		{
			Printf1Student(S[index]);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Doi mat khau" << endl;
			ChangepassStudent(S, n, id);
			UpdatefileStudent(S, n);
			system("pause");
			break;
		}
		case 3:
		{
			PrintfClass(C, c);
			system("pause");
			break;
		}
		case 4:
		{
			string tenlop;
			PrintfStuClass(C, c, tenlop);
			system("pause");
			break;
		}
		case 5:
		{

		}
		case 0:
		{
			cout << "Ban muon dang xuat?" << endl;
			cout << "0.Dong Y     1.Huy" << endl;
			index = -1;
			cin >> k;
			system("pause");
		}
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
		f1 << "ID" << "," << "Ho" << "," << "Ten" << "," << "Lop" << "," << "Khoa" << "," << "Gioi tinh" << "," << "Ngay sinh" << "," << "Id xa hoi" << "," << "Mat khau" << endl;
		for (int i = 0;i < n;i++)
		{
			f1 << S[i].ID << "," << S[i].ho << "," << S[i].ten << "," << S[i].Lop << "," << S[i].Khoa << "," << S[i].gioitinh << "," << S[i].ngaysinh << "," << S[i].IdXaHoi << "," << S[i].matkhau << endl;
		}
	}
	f1.close();
}
void CreateNewStudyYear(namhoc& newyear)
{
	cout << "Nhap nam hoc ban tao moi: ";cin >> newyear.Nienkhoa;
	newyear.HK = NULL;
	newyear.HK = NULL;
	cout << "Ban da tao thanh cong nam hoc " << newyear.Nienkhoa << " - " << newyear.Nienkhoa + 1 << endl;
}
int CountClass()
{
	int dem = 0;
	ifstream f;
	f.open("DSLop.csv");
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
void CreateClass(Lophoc*& C, int& c)
{
	ifstream f;
	C = new Lophoc[CountClass()];
	f.open("DSLop.csv", ios::in);
	if (!f.is_open())
	{
		cout << "khong the mo file";
		return;
	}
	string line;
	getline(f, line);
	int i = 0;
	while (!f.eof())
	{
		getline(f, C[i].tenlop, ',');
		getline(f, C[i].tenkhoa, ',');
		getline(f, C[i].soluong);
		i++;
	}
	c = i - 1;
	f.close();
	cout << "Danh Sach cac lop hoc da tao" << endl;
	for (int i = 0;i < c;i++)
	{
		cout << i + 1 << ". " << C[i].tenlop << endl;
	}
}
int CountStudentClass(hocsinh* S, string tenlop, int n)
{
	int dem = 0;
	for (int i = 0;i < n;i++)
	{
		if (S[i].Lop == tenlop)
			dem++;
	}
	return dem;
}
void AddStuToClass(Lophoc*& C, hocsinh* S, int c, int n)//them sinh vien vao cac lop
{
	int k = 0;
	for (int i = 0;i < c;i++)
	{
		C[i].ClassStu = new hocsinh[CountStudentClass(S, C[i].tenlop, n)];
		for (int j = 0;j < CountStudentClass(S, C[i].tenlop, n);j++)
		{
			C[i].ClassStu[j] = S[k];
			k++;
		}
	}
}
void MenuSystem()
{
	cout << "==================================================================\n";
	cout << "|<<<<<<<<<<<<<<<<   LEARNING MANAGEMENT SYSTEM   >>>>>>>>>>>>>>>>|\n";
	cout << "|----------------------------------------------------------------|\n";
	cout << "|----------------            MENU SYSTEM         ----------------|\n\n";
	cout << "_________________________________________________________________\n";
	cout << "+****************************************************************+" << endl;
	cout << "*     1.Tao moi mot nam hoc                                      *" << endl;
	cout << "*     2.Tao mot so lop hoc cho sinh vien nam nhat                *" << endl;
	cout << "*     3.Them hoc sinh vao cac lop nam nhat                       *" << endl;
	cout << "*     4.Tao hoc ki moi                                           *" << endl;
	cout << "*     5.Them cac khoa hoc vao hoc ki nay                         *" << endl;
	cout << "*     6.Xuat cac sinh vien da dang ki khoa hoc ra tep            *" << endl;
	cout << "*     7.Xem danh sach cac khoa hoc                               *" << endl;
	cout << "*     8.Cap nhat thong tin khoa hoc                              *" << endl;
	cout << "*     9.Them hoc vien vao khoa hoc                               *" << endl;
	cout << "*     10.Xoa mot hoc vien ra khoi khoa hoc                       *" << endl;
	cout << "*     11.Xoa khoa hoc                                            *" << endl;
	cout << "*     12.Xem danh sach hoc vien trong mot khoa hoc               *" << endl;
	cout << "*     13.Xu?t danh sách sinh viên trong khóa h?c ra file CSV     *" << endl;
	cout << "*     14.Nh?p b?ng ?i?m c?a m?t khóa h?c                         *" << endl;
	cout << "*     15.Xem b?ng ?i?m c?a m?t khóa h?c                          *" << endl;
	cout << "*     16.C?p nh?t k?t qu? c?a h?c sinh                           *" << endl;
	cout << "*     17.Xem b?ng ?i?m c?a l?p                                   *" << endl;
	cout << "*     0.EXIT                                                     *" << endl;
	cout << "+*********************************************************************+" << endl;

}
void MenuTeacher()
{
	cout << "==================================================================\n";
	cout << "|<<<<<<<<<<<<<<<<   LEARNING MANAGEMENT SYSTEM   >>>>>>>>>>>>>>>>|\n";
	cout << "|----------------------------------------------------------------|\n";
	cout << "|----------------            MENU SYSTEM         ----------------|\n\n";
	cout << "_________________________________________________________________\n";
	cout << "+*********************************************************+" << endl;
	cout << "*     1.Xem thong tin ca nhan                             *" << endl;
	cout << "*     2.Thay doi mat khau                                 *" << endl;
	cout << "*     3.Xem danh sach cac lop                             *" << endl;
	cout << "*     4.Xem danh sach cac hoc sinh trong lop              *" << endl;
	cout << "*     5.Xem danh sach cac khoa hoc                        *" << endl;
	cout << "      0.Dang xuat                                         +" << endl;
	cout << "+*********************************************************+" << endl;

}
int CountCourse()
{
	int dem = 0;
	fstream f;
	f.open("Khoahoc.csv");
	if (!f.is_open())
	{
		cout << "Can't open file" << endl;
		return 0;
	}
	string line;
	while (f)
	{
		getline(f, line);
		dem++;
	}
	f.close();
	return dem - 2;
}
void CreateSemester(namhoc& newyear)
{
	newyear.HK = new hocki[3];
	newyear.HK[0].ten = "Hoc Ki 1";
	newyear.HK[1].ten = "Hoc Ki 2";
	newyear.HK[2].ten = "Hoc Ki 3";
	newyear.HK[0].K = new Khoahoc[CountCourse()];
	cout << "Ban vua tao ba hoc ki cua nam hoc " << newyear.Nienkhoa << "-" << newyear.Nienkhoa + 1 << endl;
}
void PrintfClass(Lophoc* C, int c)
{
	cout << "-----Danh sach cac lop hoc----" << endl;
	for (int i = 0;i < c;i++)
	{
		cout << "1." << C[i].tenlop << endl;
	}
}
void PrintfStuClass(Lophoc* C, int c, string& tenlop)
{
	int dk = 0;
	do {
		cout << "Nhap ten lop can in Danh Sach: ";cin >> tenlop;
		for (int i = 0;i < c;i++)
		{
			if (C[i].tenlop == tenlop)
			{
				cout << "Danh sach lop " << C[i].tenlop << endl;
				for (int j = 0;j < stoi(C[i].soluong);j++)
				{
					Printf1Student(C[i].ClassStu[j]);
				}
				dk = 1;
				break;
			}
		}
		if (dk == 0)
		{
			cout << "Ban nhap sai ten lop!" << endl;
			cout << "Nhap lai: ";
		}
	} while (dk == 0);
}
void PrintfCoursse(Khoahoc* K, int& k)
{

}