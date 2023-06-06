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
struct khoahoc {
	int tinchi;
	int soluong;
	ngaythang batdau;
	ngaythang ketthuc;
	string id;
	string tenkhoa;
	string tenGiaovien;
	string tenlop;
	string ngay;
	string buoi;
};
int demHocsinh();
int demgiaovien();
void Docfilehs(hocsinh*& S, int& n);
void Docfilegv(Giaovien*& T, int& m);
bool checkPassIDhs(hocsinh* S, string id, string pass, int n, int& index);
bool checkPassIDgv(Giaovien* T, string id, string pass, int m, int& index2);
void xuat1hs(hocsinh S);
void xuatHS(hocsinh* S, int n);
void xuat1GV();
void xuatGV(Giaovien* T, int m);
void login(string& id, string& pass);
void MenuHS(hocsinh* S, int& index, int n, string id);
void MenuHeThong();
void changepasshs(hocsinh*& S, int n, string id);
void capnhatfilehs(hocsinh*& S, int n);
void taonamhoc(int& newyear);
void themlophocvaonam1();