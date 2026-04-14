#include "Tam_Giac.h"
#include <iostream>

using namespace std;

int main()
{
    cTamGiac tamGiac;
    tamGiac.Nhap();
    tamGiac.Xuat();

    // Tịnh tiến tam giác theo vector (dx, dy)
    double dx = 2.0, dy = 3.0;
    cout << "\nTinh tien tam giac theo vector (" << dx << ", " << dy << "):\n";
    tamGiac.TinhTien(dx, dy);
    tamGiac.Xuat();

    // Quay tam giác quanh gốc tọa độ (0,0) một góc (độ)
    double angle = 45.0; // Quay 45 độ
    cout << "\nQuay tam giac quanh goc toa do mot goc " << angle << " do:\n";
    tamGiac.Quay(angle);
    tamGiac.Xuat();

    // Phóng to tam giác theo tỉ lệ k
    double k = 2.0; // Phóng to gấp đôi
    cout << "\nPhong to tam giac theo ti le " << k << ":\n";
    tamGiac.PhongTo(k);
    tamGiac.Xuat();

    // Thu nhỏ tam giác theo tỉ lệ k
    double k2 = 2.0; // Thu nhỏ còn một nửa
    cout << "\nThu nho tam giac theo ti le " << k2 << ":\n";
    tamGiac.ThuNho(k2);
    tamGiac.Xuat();

    return 0;
}