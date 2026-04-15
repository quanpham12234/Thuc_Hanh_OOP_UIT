#ifndef DS_PHANSO_H
#define DS_PHANSO_H

#include <iostream>
#include <vector>

using namespace std;

// Lớp PHÂN SỐ
class PhanSo
{
private:
    int tuSo;  // Tử số
    int mauSo; // Mẫu số
public:
    // Constructor mặc định
    PhanSo();

    // Constructor có tham số
    PhanSo(int tu, int mau);

    // Hàm nhập phân số
    friend istream &operator>>(istream &in, PhanSo &ps);

    // Hàm xuất phân số
    friend ostream &operator<<(ostream &out, const PhanSo &ps);

    // Lấy tử số
    int getTuSo() const;

    // Lấy mẫu số
    int getMauSo() const;

    // Hàm rút gọn phân số
    void RutGon();

    // Hàm chuẩn hóa dấu của phân số
    void ChuanHoaDau();

    // Hàm cộng hai phân số
    PhanSo operator+(const PhanSo &other) const;

    // Hàm so sánh hai phân số <
    bool operator<(const PhanSo &other) const;

    // Hàm so sánh hai phân số >
    bool operator>(const PhanSo &other) const;
};

// Lớp DANH SÁCH PHÂN SỐ
class DSPhanSo
{
private:
    vector<PhanSo> ds; // Danh sách phân số

public:
    // Constructor mặc định
    DSPhanSo();

    // Constructor có tham số
    DSPhanSo(const vector<PhanSo> &danhSach);

    // Hàm nhập danh sách phân số
    void Nhap();

    // Hàm xuất danh sách phân số
    void Xuat() const;

    // Tính tổng các phân số trong danh sách
    PhanSo Tong() const;

    // Tìm phân số lớn nhất trong danh sách
    PhanSo LonNhat() const;

    // Tìm phân số nhỏ nhất trong danh sách
    PhanSo NhoNhat() const;

    // Tìm phân số có tử là số nguyên tố lớn nhất
    PhanSo TuSoNguyenToLonNhat() const;

    // Sắp xếp danh sách phân số theo thứ tự tăng dần
    void SapXepTangDan();

    // Sắp xếp danh sách phân số theo thứ tự giảm dần
    void SapXepGiamDan();
};

#endif