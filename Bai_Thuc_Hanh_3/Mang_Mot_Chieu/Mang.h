#ifndef MANG_H
#define MANG_H

#include <iostream>
#include <vector>

using namespace std;

class cArray
{
private:
    vector<int> arr; // Mảng động sử dụng vector

public:
    // Constructor mặc định
    cArray();

    // Tạo mảng ngẫu nhiên gồm n số nguyên
    cArray(int n);

    // Xuất mảng
    void Xuat() const;

    // Đếm số lần xuất hiện của giá trị x trong mảng
    int DemSoLanXuatHien(int x) const;

    // Kiểm tra các phần tử trong mảng có tăng dần hay không
    bool KiemTraTangDan() const;

    // Tìm phần lẻ nhỏ nhất trong mảng
    int TimLeNhoNhat() const;

    // Tìm số nguyên tố lớn nhất trong mảng
    int TimNguyenToLonNhat() const;

    // Sắp xếp mảng theo thứ tự tăng dần
    void SapXepTangDan();

    // Sắp xếp mảng theo thứ tự giảm dần
    void SapXepGiamDan();
};

#endif