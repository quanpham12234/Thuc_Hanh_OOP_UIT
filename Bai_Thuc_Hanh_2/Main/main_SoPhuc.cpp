#include <iostream>
#include "../Header/So_Phuc.h"
using namespace std;

int main() {
    SoPhuc sp1, sp2, kq;

    cout << "Nhap so phuc thu nhat:\n";
    sp1.Nhap();

    cout << "\nNhap so phuc thu hai:\n";
    sp2.Nhap();

    cout << "\nSo phuc thu nhat: ";
    sp1.Xuat();

    cout << "\nSo phuc thu hai: ";
    sp2.Xuat();

    cout << "\n\nTong: ";
    kq = sp1.Tong(sp2);
    kq.Xuat();

    cout << "\nHieu: ";
    kq = sp1.Hieu(sp2);
    kq.Xuat();

    cout << "\nTich: ";
    kq = sp1.Tich(sp2);
    kq.Xuat();

    cout << "\nThuong: ";
    kq = sp1.Thuong(sp2);
    kq.Xuat();
    
    return 0;
}