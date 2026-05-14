#include "So_Phuc.h"

// Constructor
SoPhuc::SoPhuc() {
    iThuc = 0;
    iAo = 0;
}

// Nạp chồng toán tử nhập
istream &operator>>(istream &in, SoPhuc &sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.iThuc;
    cout << "Nhap phan ao: ";
    in >> sp.iAo;
    return in;
}

// Nạp chồng toán tử xuất
ostream &operator<<(ostream &out, const SoPhuc &sp) {
    out << sp.iThuc << " + " << sp.iAo << "i";
    return out;
}

// Nạp chồng toán tử +
SoPhuc SoPhuc::operator+(const SoPhuc &sp) const {
    SoPhuc result;
    result.iThuc = iThuc + sp.iThuc;
    result.iAo = iAo + sp.iAo;
    return result;
}

// Nạp chồng toán tử -
SoPhuc SoPhuc::operator-(const SoPhuc &sp) const {
    SoPhuc result;
    result.iThuc = iThuc - sp.iThuc;
    result.iAo = iAo - sp.iAo;
    return result;
}

// Nạp chồng toán tử *
SoPhuc SoPhuc::operator*(const SoPhuc &sp) const {
    SoPhuc result;
    result.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    result.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return result;
}

// Nạp chồng toán tử /
SoPhuc SoPhuc::operator/(const SoPhuc &sp) const {
    SoPhuc result;
    int denominator = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (denominator == 0) {
        throw runtime_error("Khong the chia cho so phuc co phan thuc va phan ao deu la 0.");
    }
    result.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / denominator;
    result.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / denominator;
    return result;
}

// Nạp chồng toán tử ==
bool SoPhuc::operator==(const SoPhuc &sp) const {
    return (iThuc == sp.iThuc) && (iAo == sp.iAo);
}

// Nạp chồng toán tử !=
bool SoPhuc::operator!=(const SoPhuc &sp) const {
    return !(*this == sp);
}