#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
using namespace std;

class DaThuc
{                                                                                                                                               
private:
    int bac;      // Bậc của đa thức
    double *heSo; // Mảng động lưu hệ số, heSo[i] tương ứng với hệ số của x^i

public:
    // Các hàm thiết lập và hủy
    DaThuc();                    // Khởi tạo mặc định (đa thức bậc 0, hệ số 0)
    DaThuc(int b);               // Khởi tạo đa thức bậc b
    DaThuc(const DaThuc &other); // Copy constructor (Hàm thiết lập sao chép)
    ~DaThuc();                   // Hàm hủy

    // Toán tử nhập xuất
    friend istream &operator>>(istream &is, DaThuc &dt);
    friend ostream &operator<<(ostream &os, const DaThuc &dt);

    // Toán tử gán
    DaThuc &operator=(const DaThuc &other);

    // Toán tử số học
    DaThuc operator+(const DaThuc &other) const;
    DaThuc operator-(const DaThuc &other) const;

    // Toán tử tính giá trị đa thức tại một điểm x (thực hiện P(x))
    double operator()(double x) const;
};

#endif