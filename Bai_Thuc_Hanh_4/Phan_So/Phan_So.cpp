#include "Phan_So.h"

// Hàm tìm ước chung lớn nhất, phục vụ cho việc rút gọn phân số
int UCLN(int a, int b) {
    if (b == 0) return abs(a);
    return UCLN(b, a % b);
}

// Constructor
PhanSo::PhanSo() {
    iTu = 0;
    iMau = 1; // Mẫu số mặc định là 1 để tránh chia cho 0
}

// Hàm rút gọn phân số
void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;

    // Đảm bảo mẫu số luôn dương
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Nạp chồng toán tử nhập
istream &operator>>(istream &in, PhanSo &ps) {
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau;
    ps.RutGon(); // Rút gọn phân số sau khi nhập
    return in;
}

// Nạp chồng toán tử xuất
ostream &operator<<(ostream &out, const PhanSo &ps) {
    out << ps.iTu << "/" << ps.iMau;
    return out;
}

// Nạp chồng toán tử +
PhanSo PhanSo::operator+(const PhanSo &ps) const {
    PhanSo result;
    result.iTu = iTu * ps.iMau + ps.iTu * iMau;
    result.iMau = iMau * ps.iMau;
    result.RutGon();
    return result;
}

// Nạp chồng toán tử -
PhanSo PhanSo::operator-(const PhanSo &ps) const {
    PhanSo result;
    result.iTu = iTu * ps.iMau - ps.iTu * iMau;
    result.iMau = iMau * ps.iMau;
    result.RutGon();
    return result;
}

// Nạp chồng toán tử *
PhanSo PhanSo::operator*(const PhanSo &ps) const {
    PhanSo result;
    result.iTu = iTu * ps.iTu;
    result.iMau = iMau * ps.iMau;
    result.RutGon();
    return result;
}

// Nạp chồng toán tử /
PhanSo PhanSo::operator/(const PhanSo &ps) const {
    PhanSo result;
    result.iTu = iTu * ps.iMau;
    result.iMau = iMau * ps.iTu;
    result.RutGon();
    return result;
}

// Nạp chồng toán tử ==
bool PhanSo::operator==(const PhanSo &ps) const {
    return (iTu == ps.iTu) && (iMau == ps.iMau);
}

// Nạp chồng toán tử >
bool PhanSo::operator>(const PhanSo &ps) const {
    return (iTu * ps.iMau > ps.iTu * iMau);
}

// Nạp chồng toán tử <
bool PhanSo::operator<(const PhanSo &ps) const {
    return (iTu * ps.iMau < ps.iTu * iMau);
}