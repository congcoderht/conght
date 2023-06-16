#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
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
struct Node {
	hocsinh hs;
	Node* Next;
};
struct List {
	Node* head;
};
struct ngaythang {
	int ngay;
	int thang;
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
	string soluong;
	hocsinh* ClassStu;
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
	List hs;
};
struct hocki {
	string ten;
	Khoahoc* K;
	string ngaybatdau;
	string ngayketthuc;
};
struct namhoc {
	hocki* HK;
	int Nienkhoa;
};
Node* CreateNode(hocsinh a);//tao 1 Node chua sinh vien a
void addTail(List& l, hocsinh a);//them hoc sinh vao dslk
int CountStudent();//dem so luong sinh vien
int CountTeacher();//dem so luong giao vien
int CountClass();//dem so luong lop hoc
void ReadStudent(hocsinh*& S, int& n);//Doc thong tin sinh vien ra tu file
void ReadTeacher(Giaovien*& T, int& m);//Doc thong tin giao vien ra tu file
bool CheckPassIDStudent(hocsinh* S, string id, string pass, int n, int& index);//kiem tra tk dang nhap co phai cua hs k
bool CheckPassIDTeacher(Giaovien* T, string id, string pass, int m, int& index2);//kt xem co phai tk cua giao vien hay khong
void Printf1Student(hocsinh S);//xuat thong tin cua 1 sinh vien
void PrintfStudent(hocsinh* S, int n);//Xuat thong tin toan bo sinh vien
void Printf1Teacher();//xuat thong tin cua 1 giao vien
void PrintfTeacher(Giaovien* T, int m);//Xuat thong tin toan bo giao vien
void login(string& id, string& pass);//nhap tai khoan
void MenuStudent(hocsinh* S, Lophoc* C, int& index, int n, int c, string id);//Menu rieng khi dang nhap tai khoan la hoc sinh
void MenuSystem();//Menu cho he thong(tao lop,khoa hoc)
void MenuTeacher();//Menu cho giao vien
void ChangepassStudent(hocsinh*& S, int n, string id);//Thay doi mat khau cua sinh vien
void UpdatefileStudent(hocsinh*& S, int n);//cap nhat cac thong tin sinh vien trong file
void CreateNewStudyYear(namhoc& newyear);//tao 1 nam hoc moi
void AddFirstClass();//them 1 lop hoc vao nam hoc moi
void CreateClass(Lophoc*& C, int& c);//tao cac lop hoc
void PrintfClass(Lophoc* C, int c);//in ra danh sach cac lop hoc
int CountStudentClass(hocsinh* S, string tenlop, int n);//dem so hoc sinh cua 1 lop
void AddStuToClass(Lophoc*& C, hocsinh* S, int c, int n);//them sinh vien vao cac lop
int CountCourse();//dem so khoa hoc da duoc tao trong file
void PrintfCoursse(Khoahoc* K, int& k);//in ra danh sach khoa hoc
void CreateSemester(namhoc& newyear);//tao hoc ki
void PrintfStuClass(Lophoc* C, int c, string& tenlop);//in ra danh sach hoc sinh trong 1 lop
void AddCourse(namhoc& newyear);//them cac khoa hoc vao hoc ki hien tai


