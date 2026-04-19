#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Cấu trúc để lưu ngày sinh
struct Date{
    int day, month, year;

    // Toán tử so sánh để so sánh ngày sinh (dùng cho tìm nhân viên lớn tuổi nhất) 
    bool operator>(const Date &other) const;
};

// Lớp cNhanVienVP để lưu thông tin nhân viên văn phòng
class cNhanVienVP {
    private:
    string Id;
    string Name;
    Date date;
    double Salary;

    public:
    // Constructor mặc định cho lớp cNhanVienVP 
    cNhanVienVP();

    // Thao tác get
    string getId() const;
    string getName() const;
    Date getDate() const;
    double getSalary() const;

    // Thao tác set
    void setId(const string &id);
    void setName(const string &name);
    void setDate(const Date &date);
    void setSalary(double salary);

    // Nhập thông tin cho nhân viên
    friend istream &operator>>(istream &in, cNhanVienVP &a);

    // Xuất thông tin của nhân viên
    friend ostream &operator<<(ostream &out, const cNhanVienVP &a);
};

// Lớp clistNhanVienVP để quản lý danh sách nhân viên văn phòng
class clistNhanVienVP {
    private:
    vector<cNhanVienVP> list; // Sử dụng vector để lưu danh sách nhân viên

    public:
    // Constructor mặc định cho lớp clistNhanVienVP
    clistNhanVienVP();

    // Nhập thông tin n nhân viên
    void Nhap();

    // Xuất thông tin nhân viên trong danh sách
    void Xuat();

    // Nhân viên có lương cao nhất
    cNhanVienVP Nhan_Vien_Luong_Cao_Nhat();

    // Tổng lương công ty phải trả cho nhân viên
    double Tong_Luong();

    // Nhân viên lớn tuổi nhất
    cNhanVienVP Nhan_Vien_Lon_Tuoi_Nhat();

    // Sắp xếp danh sách nhân viên theo lương tăng dần
    void Sap_Xep_Luong_Tang_Dan();
};

#endif