#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
    private:
    int iTu;
    int iMau;

    public:
    // Constructor mặc định
    PhanSo();

    // Hàm rút gọn phân số
    void RutGon();

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, PhanSo &ps);

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, const PhanSo &ps);

    // Nạp chồng toán tử +
    PhanSo operator+(const PhanSo &ps) const;

    // Nạp chồng toán tử -
    PhanSo operator-(const PhanSo &ps) const;

    // Nạp chồng toán tử *
    PhanSo operator*(const PhanSo &ps) const;

    // Nạp chồng toán tử /
    PhanSo operator/(const PhanSo &ps) const;

    // Nạp chồng toán tử ==
    bool operator==(const PhanSo &ps) const;

    // Nạp chồng toán tử >
    bool operator>(const PhanSo &ps) const;

    // Nạp chồng toán tử <
    bool operator<(const PhanSo &ps) const;
};

#endif
