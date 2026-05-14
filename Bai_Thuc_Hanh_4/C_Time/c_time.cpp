#include "c_time.h"

// Constructor
cTime::cTime() {
    iGio = 0;
    iPhut = 0;
    iGiay = 0;
}

// Constructor có tham số
cTime::cTime(int gio, int phut, int giay) {
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
    chuanHoa();
}

// Chuẩn hoá thời gian để giây/phút/giờ nằm trong phạm vi hợp lệ
void cTime::chuanHoa() {
    if (iGiay >= 60) {
        iPhut += iGiay / 60;
        iGiay %= 60;
    } else if (iGiay < 0) {
        int borrow = (-iGiay + 59) / 60;
        iPhut -= borrow;
        iGiay += borrow * 60;
    }

    if (iPhut >= 60) {
        iGio += iPhut / 60;
        iPhut %= 60;
    } else if (iPhut < 0) {
        int borrow = (-iPhut + 59) / 60;
        iGio -= borrow;
        iPhut += borrow * 60;
    }

    if (iGio >= 24) {
        iGio %= 24;
    } else if (iGio < 0) {
        iGio = (iGio % 24 + 24) % 24;
    }
}

// Nạp chồng toán tử nhập
istream &operator>>(istream &in, cTime &tg) {
    cout << "Nhap gio: ";
    in >> tg.iGio;
    cout << "Nhap phut: ";
    in >> tg.iPhut;
    cout << "Nhap giay: ";
    in >> tg.iGiay;
    return in;
}

// Nạp chồng toán tử xuất
ostream &operator<<(ostream &out, const cTime &tg) {
    out << tg.iGio << " gio " << tg.iPhut << " phut " << tg.iGiay << " giay";
    return out;
}

// Nạp chồng toán tử +
cTime cTime::operator+(const cTime &tg) const {
    cTime result(iGio + tg.iGio, iPhut + tg.iPhut, iGiay + tg.iGiay);
    result.chuanHoa();
    return result;
}

// Nạp chồng toán tử ++ (tiền tố)
cTime &cTime::operator++() {
    *this = *this + cTime(0,0,1); // Cộng thêm 1 giây
    return *this;
}

// Nạp chồng toán tử ++ (hậu tố)
cTime cTime::operator++(int) {
    cTime temp = *this; // Lưu giá trị hiện tại
    *this = *this + cTime(0, 0, 1); // Cộng thêm 1 giây
    return temp; // Trả về giá trị trước khi tăng
}

// Nạp chồng toán tử -
cTime cTime::operator-(const cTime &tg) const {
    cTime result;
    int totalGiay1 = iGio * 3600 + iPhut * 60 + iGiay;
    int totalGiay2 = tg.iGio * 3600 + tg.iPhut * 60 + tg.iGiay;
    int diffGiay = totalGiay1 - totalGiay2;

    result.iGio = diffGiay / 3600;
    result.iPhut = (diffGiay % 3600) / 60;
    result.iGiay = diffGiay % 60;

    result.chuanHoa();    

    return result;
}

// Nạp chồng toán tử -- (tiền tố)
cTime &cTime::operator--() {
    int totalGiay = iGio * 3600 + iPhut * 60 + iGiay;
    totalGiay = (totalGiay + 24 * 3600 - 1) % (24 * 3600);
    iGio = totalGiay / 3600;
    iPhut = (totalGiay % 3600) / 60;
    iGiay = totalGiay % 60;
    return *this;
}

// Nạp chồng toán tử -- (hậu tố)
cTime cTime::operator--(int) {
    cTime temp = *this; // Lưu giá trị hiện tại
    --*this;
    return temp; // Trả về giá trị trước khi giảm
}
