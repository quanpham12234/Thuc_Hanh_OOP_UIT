#include <iostream>
#include "../Header/Thoi_Gian.h"
using namespace std;

int main() {
    ThoiGian tg;
    tg.Nhap();
    
    cout << "Thoi gian vua nhap: ";
    tg.Xuat();

    ThoiGian next_tg = tg.TinhCongThemMotGiay();
    cout << "Thoi gian tinh cong them mot giay: ";
    next_tg.Xuat();

    cout << endl << endl << endl;
    int a; cin >> a;

    return 0;
}