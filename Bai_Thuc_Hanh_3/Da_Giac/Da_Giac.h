#ifndef DAGIAC_H
#define DAGIAC_H

#include <iostream>
#include <vector>
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

class cDaGiac
{
private:
    vector<Diem> a; // Các đỉnh của đa giác

    double DoDai(const Diem &a, const Diem &b) const;

public:
    // Constructor (hàm tạo)
    cDaGiac();

    // Destructor (hàm hủy)
    ~cDaGiac();

    // Nhập dữ liệu đa giác
    void Nhap();

    // Tính chu vi đa giác
    double ChuVi() const;

    // Tính diện tích (dùng công thức Shoelace)
    double DienTich() const;

    // Xuất thông tin đa giác
    void Xuat() const;

    // Tịnh tiến đa giác theo vector (dx, dy)
    void TinhTien(double dx, double dy);

    // Quay đa giác quanh gốc tọa độ (0,0) một góc (độ)
    void Quay(double angle);

    // Phóng to đa giác theo tỉ lệ k
    void PhongTo(double k);

    // Thu nhỏ đa giác theo tỉ lệ k
    void ThuNho(double k);
};

#endif