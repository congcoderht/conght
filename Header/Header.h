#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
struct ngaythang {
	int ngay;
	int thang;
};
struct hocsinh {
	string ID;
	string ho;
	string ten;
	string Lop;
	string Khoa;
	string ngaysinh;
	string IdXaHoi;
	string gioitinh;
	string matkhau;
};
struct Giaovien {
	string id;
	string ho;
	string ten;
	string ngaysinh;
	string IDXH;
	string gioitinh;
	string matkhau;
};
struct Lophoc {
	string tenlop;
	string tenkhoa;
	int soluong;
};
struct Khoahoc {
	string ID;
	string tenkhoa;
	string tenlop;
	string tenGV;
	int soTC;
	int SL;
	string ngayhoc;
	string giohoc;
	int ngaybd;
	int ngaykt;
};
struct namhoc {
	Khoahoc* khoa;
	Lophoc* lop;
	int Nienkhoa;
};
int CountStudent();//dem so luong sinh vien
int CountTeacher();//dem so luong giao vien
void ReadStudent(hocsinh*& S, int& n);//Doc thong tin sinh vien ra tu file
void ReadTeacher(Giaovien*& T, int& m);//Doc thong tin giao vien ra tu file
bool CheckPassIDStudent(hocsinh* S, string id, string pass, int n, int& index);//kiem tra tk dang nhap co phai cua hs k
bool CheckPassIDTeacher(Giaovien* T, string id, string pass, int m, int& index2);//kt xem co phai tk cua giao vien hay khong
void Printf1Student(hocsinh S);//xuat thong tin cua 1 sinh vien
void PrintfStudent(hocsinh* S, int n);//Xuat thong tin toan bo sinh vien
void Printf1Teacher();//xuat thong tin cua 1 giao vien
void PrintfTeacher(Giaovien* T, int m);//Xuat thong tin toan bo giao vien
void login(string& id, string& pass);//nhap tai khoan
void MenuStudent(hocsinh* S, int& index, int n, string id);//Menu rieng khi dang nhap tai khoan la hoc sinh
void MenuSystem();//Menu cho he thong(tao lop,khoa hoc....
void ChangepassStudent(hocsinh*& S, int n, string id);//Thay doi mat khau cua sinh vien
void UpdatefileStudent(hocsinh*& S, int n);//cap nhat cac thong tin sinh vien trong file
void CreateNewStudyYear(namhoc& newyear);//tao 1 nam hoc moi
void AddFirstClass();//them 1 lop hoc vao nam hoc moi