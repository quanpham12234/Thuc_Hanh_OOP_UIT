#ifndef TAMGIAC_H   // Tránh include nhiều lần
#define TAMGIAC_H

#include <iostream>
using namespace std;

// Lớp ĐIỂM (Point)
class Diem
{
public:
    double x, y; // tọa độ điểm trong mặt phẳng Oxy

    // Constructor mặc định
    Diem();

    // Constructor có 2 tham số x1, y1
    Diem(double x1, double y1);

    // Khoảng cách tới gốc tọa độ
    double KhoachangToiGoc() const;

    // Nạp chồng toán tử nhập (cin >>)
    // Cho phép nhập trực tiếp: cin >> diem;
    friend istream &operator>>(istream &in, Diem &a);

    // Nạp chồng toán tử xuất (cout <<)
    // Cho phép in trực tiếp: cout << diem;
    friend ostream &operator<<(ostream &out, const Diem &a);
};

// Lớp TAM GIÁC
class cTamGiac
{
private:
    Diem A, B, C; // 3 đỉnh của tam giác

    double DoDai(const Diem &a, const Diem& b) const;

public:
    // Constructor (hàm tạo)
    cTamGiac();

    // Destructor (hàm hủy)
    ~cTamGiac();

    // Nhập dữ liệu tam giác
    void Nhap();

    // Xác định loại tam giác:
    // thường, cân, vuông, đều
    string LoaiTamGiac();

    // Tính chu vi tam giác
    double ChuVi();

    // Tính diện tích (dùng công thức Heron)
    double DienTich();

    // Xuất thông tin tam giác
    void Xuat();

    // Tịnh tiến tam giác theo vector (dx, dy)
    void TinhTien(double dx, double dy);

    // Quay tam giác quanh gốc tọa độ (0,0) một góc (độ)
    void Quay(double angle);

    // Phóng to tam giác theo tỉ lệ k
    void PhongTo(double k);

    // Thu nhỏ tam giác theo tỉ lệ k
    void ThuNho(double k);
};

#endif