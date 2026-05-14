#include "c_date.h"

// Hàm chuyển đổi ngày tháng năm thành số ngày kể từ 01/01/0000 để tính toán số ngày giữa 2 thời gian
int c_Date::toDays() const {
    int y = iNam;
    int m = iThang;
    int d = iNgay;

    if (m < 3) {
        y--;
        m += 12;
    }

    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

// Hàm tìm số ngày trong tháng, năm. Phục vụ cho việc chuẩn hóa ngày tháng năm
int daysInMonth(int month, int year) {
    if (month == 2) {
        // Năm nhuận
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
        return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// Chuẩn hóa ngày tháng năm để ngày, tháng, năm nằm trong phạm vi hợp lệ
void c_Date::chuanHoa() {
    while (iNgay > daysInMonth(iThang, iNam)) {
        iNgay -= daysInMonth(iThang, iNam);
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }

    while (iNgay < 1) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        iNgay += daysInMonth(iThang, iNam);
    }

    while (iThang > 12) {
        iThang -= 12;
        iNam++;
    }

    while (iThang < 1) {
        iThang += 12;
        iNam--;
    }
}

// Constructor mặc định
c_Date::c_Date() {
    iNgay = 1;
    iThang = 1;
    iNam = 2000;
}

// Constructor có tham số
c_Date::c_Date(int ngay, int thang, int nam) {
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
    chuanHoa();
}

// Nạp chồng toán tử nhập
istream &operator>>(istream &in, c_Date &date) {
    cout << "Nhap ngay: ";
    in >> date.iNgay;
    cout << "Nhap thang: ";
    in >> date.iThang;
    cout << "Nhap nam: ";
    in >> date.iNam;
    date.chuanHoa();
    return in;
}

// Nạp chồng toán tử xuất
ostream &operator<<(ostream &out, const c_Date &date) {
    if (date.iNgay < 10) out << "0";
    out << date.iNgay << "/";
    if (date.iThang < 10) out << "0";
    out << date.iThang << "/" << date.iNam;
    return out;
}

// Nạp chồng toán tử +
c_Date c_Date::operator+(int days) const {
    c_Date result = *this;
    result.iNgay += days;
    result.chuanHoa();
    return result;
}

// Nạp chồng toán tử ++ (tiền tố)
c_Date &c_Date::operator++() {
    iNgay++;
    chuanHoa();
    return *this;
}

// Nạp chồng toán tử ++ (hậu tố)
c_Date c_Date::operator++(int) {
    c_Date temp = *this;
    iNgay++;
    chuanHoa();
    return temp;
}

// Nạp chồng toán tử -
c_Date c_Date::operator-(int days) const {
    c_Date result = *this;
    result.iNgay -= days;
    result.chuanHoa();
    return result;
}

// Nạp chồng toán tử -- (tiền tố)
c_Date &c_Date::operator--() {
    iNgay--;
    chuanHoa();
    return *this;
}

// Nạp chồng toán tử -- (hậu tố)
c_Date c_Date::operator--(int) {
    c_Date temp = *this;
    iNgay--;
    chuanHoa();
    return temp;
}

// Hàm tính số ngày giữa 2 thời gian
int c_Date::daysBetween(const c_Date &other) const {
    return abs(this->toDays() - other.toDays());
}