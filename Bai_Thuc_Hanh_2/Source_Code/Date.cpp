#include <iostream>
#include "../Header/Date.h"

using namespace std;

// Hàm kiểm tra một năm nào đó có phải năm nhuận hay không
// Nếu là năm nhuận thì return true, còn không thì return false
bool nam_nhuan(int nam) {
    if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        return true;
    return false;
}

// Hàm kiểm tra số ngày trong 1 tháng dựa vào tháng và năm
// Hàm này hỗ trợ cho việc kiểm tra ngày hợp lệ và tìm ngày tháng năm tiếp theo dễ dàng hơn
int So_Ngay_Trong_Thang(int thang, int nam) {
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
    {
        if (nam_nhuan(nam) == true)
            return 29;
        else
            return 28;
    }
    }
    return -1;
}

void Date::Nhap() {
    do
    {
        cout << "Nhap ngay: ";
        cin >> iNgay;

        cout << "Nhap thang: ";
        cin >> iThang;

        cout << "Nhap nam: ";
        cin >> iNam;

        if (iNgay > So_Ngay_Trong_Thang(iThang,iNam))
            cout << "Ngay thang nam khong hop le! Vui long nhap lai: \n";
    } while (iNgay > So_Ngay_Trong_Thang(iThang,iNam));
}

void Date::Xuat() {
    if (iNgay < 10) cout << "0";
    cout << iNgay << "/";
    if (iThang < 10) cout << "0";
    cout << iThang << "/" << iNam << "\n";
}

Date Date::NgayThangNamTiepTheo() {
    Date next_date;
    next_date.iNgay = iNgay + 1;
    next_date.iThang = iThang;
    next_date.iNam = iNam;
    if (next_date.iNgay > So_Ngay_Trong_Thang(iThang,iNam)) {
        next_date.iNgay = 1;
        next_date.iThang = iThang + 1;
    }

    if (next_date.iThang > 12) {
        next_date.iThang = 1;
        next_date.iNam = iNam + 1;
    }

    return next_date;
}