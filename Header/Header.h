#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
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
	int ngaybatdau;
	int thangbatdau;
	int ngayketthuc;
	int thangketthuc;
	string id;
	string tenkhoa;
	string tenlop;
	string ngay;
	string buoi;
};
int demHocsinh();
void Docfilehs(hocsinh*& S,int &n);
bool checkPassIDhs(hocsinh* S, string id, string pass,int n,int &index);
void xuat1hs(hocsinh* S, string id,int n);
void xuatHS(hocsinh* S,int n);
void login(string& id, string& pass);
void changepasshs(hocsinh*& S, int n, string id);
void capnhatfilehs(hocsinh* &S, int n);
void taonamhoc(int& newyear);