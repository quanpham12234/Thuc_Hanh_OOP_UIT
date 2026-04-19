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
class cNhanVienSX {
    private:
    string Id;
    string Name;
    Date date;
    int So_San_Pham;
    double Don_Gia;

    public:
    // Constructor mặc định cho lớp cNhanVienSX
    cNhanVienSX();

    // Thao tác get
    string getId() const;
    string getName() const;
    Date getDate() const;
    int getSoSanPham() const;
    double getDonGia() const;

    // Thao tác set
    void setId(const string &id);
    void setName(const string &name);
    void setDate(const Date &date);
    void setSoSanPham(int soSanPham);
    void setDonGia(double donGia);

    // Nhập thông tin cho nhân viên
    friend istream &operator>>(istream &in, cNhanVienSX &a);

    // Xuất thông tin của nhân viên
    friend ostream &operator<<(ostream &out, const cNhanVienSX &a);

    // Tính lương của nhân viên sản xuất
    double Tinh_Luong() const;
};

// Lớp clistNhanVienSX để quản lý danh sách nhân viên sản xuất
class clistNhanVienSX {
    private:
    vector<cNhanVienSX> list; // Sử dụng vector để lưu danh sách nhân viên

    public:
    // Constructor mặc định cho lớp clistNhanVienSX
    clistNhanVienSX();

    // Nhập thông tin n nhân viên
    void Nhap();

    // Xuất thông tin nhân viên trong danh sách
    void Xuat();

    // Nhân viên có lương thấp nhất
    cNhanVienSX Nhan_Vien_Luong_Thap_Nhat();

    // Tổng lương công ty phải trả cho nhân viên
    double Tong_Luong();

    // Nhân viên lớn tuổi nhất
    cNhanVienSX Nhan_Vien_Lon_Tuoi_Nhat();

    // Sắp xếp danh sách nhân viên theo lương tăng dần
    void Sap_Xep_Luong_Tang_Dan();
};

#endif