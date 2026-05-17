#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
using namespace std;

class CVector
{
private:
    int n;          // Số chiều của vector
    double *coords; // Mảng động lưu các tọa độ (từ 0 đến n-1)

public:
    // Khởi tạo và Hủy
    CVector();
    CVector(int n);
    CVector(const CVector &other); // Copy constructor
    ~CVector();

    // Toán tử nhập xuất
    friend istream &operator>>(istream &is, CVector &v);
    friend ostream &operator<<(ostream &os, const CVector &v);

    // Toán tử gán
    CVector &operator=(const CVector &other);

    // Toán tử số học giữa 2 vector
    CVector operator+(const CVector &other) const;
    CVector operator-(const CVector &other) const;
    double operator*(const CVector &other) const; // Tích vô hướng (Dot product)

    // Toán tử nhân vector với một số thực (Scalar multiplication)
    CVector operator*(double scalar) const;

    // Toán tử truy xuất phần tử
    double &operator[](int index);

    // Lấy số chiều của vector để phục vụ CMatrix
    int getSize();
};

#endif