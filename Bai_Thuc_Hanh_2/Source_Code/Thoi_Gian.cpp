#include <iostream>
#include "../Header/Thoi_Gian.h"

using namespace std;

void ThoiGian::Nhap() {
    do
    {
        cout << "Nhap gio: ";
        cin >> iGio;

        cout << "Nhap phut: ";
        cin >> iPhut;

        cout << "Nhap giay: ";
        cin >> iGiay;

        if (iGio < 0 || iGio >= 24 || iPhut < 0 || iPhut >= 60 || iGiay < 0 || iGiay >= 60)
            cout << "Thoi gian ban nhap loi! Hay nhap lai: \n";
    } while (iGio < 0 || iGio >= 24 || iPhut < 0 || iPhut >= 60 || iGiay < 0 || iGiay >= 60);
}

void ThoiGian::Xuat() {
    if (iGio < 10)
        cout << "0"; 
    cout << iGio << "-";
    if (iPhut < 10)
        cout << "0";
    cout << iPhut << "-";
    if (iGiay < 10)
        cout << "0";
    cout << iGiay << "\n";
}

ThoiGian ThoiGian::TinhCongThemMotGiay() {
    ThoiGian new_time;
    new_time.iGiay = iGiay + 1;
    new_time.iPhut = iPhut;
    new_time.iGio = iGio;

    if (new_time.iGiay > 59) {
        new_time.iGiay = 0;
        new_time.iPhut ++;
    }

    if (new_time.iPhut > 59) {
        new_time.iPhut = 0;
        new_time.iGio ++;
    }

    if (new_time.iGio > 23) {
        new_time.iGio = 0;
        new_time.iPhut = 0;
        new_time.iGiay = 0;
    }

    return new_time;
}