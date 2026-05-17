#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include "../C_Vector/CVector.h" // Nhúng lớp CVector từ bài trước để tính tích

using namespace std;

class CMatrix
{
private:
    int rows;      // Số hàng
    int cols;      // Số cột
    double **data; // Mảng 2 chiều động lưu các phần tử

public:
    // Khởi tạo và Hủy
    CMatrix();
    CMatrix(int r, int c);
    CMatrix(const CMatrix &other); // Copy constructor
    ~CMatrix();

    // Toán tử nhập xuất
    friend istream &operator>>(istream &is, CMatrix &m);
    friend ostream &operator<<(ostream &os, const CMatrix &m);

    // Toán tử gán
    CMatrix &operator=(const CMatrix &other);

    // Toán tử cộng, trừ ma trận
    CMatrix operator+(const CMatrix &other) const;
    CMatrix operator-(const CMatrix &other) const;

    // Toán tử nhân: Ma trận x Ma trận
    CMatrix operator*(const CMatrix &other) const;

    // Toán tử nhân: Ma trận x Vector
    // Lưu ý: v truyền vào dạng tham chiếu (reference) vì toán tử [] bên CVector chưa có bản const
    CVector operator*(CVector &v) const;
};

#endif