#include "Da_Giac.h"
#include <iostream>

using namespace std;

int main()
{
    cDaGiac daGiac;
    daGiac.Nhap();
    daGiac.Xuat();
    cout << "\n";

    // Tịnh tiến đa giác theo vector (dx, dy)
    double dx, dy;
    cout << "Nhap vector tinh tien (dx, dy): ";
    cin >> dx >> dy;
    daGiac.TinhTien(dx, dy);
    cout << "Da giac sau khi tinh tien:\n";
    daGiac.Xuat();
    cout << "\n";

    // Quay đa giác quanh gốc tọa độ (0,0) một góc (độ)
    double angle;
    cout << "Nhap goc quay (do): ";
    cin >> angle;
    daGiac.Quay(angle);
    cout << "Da giac sau khi quay:\n";
    daGiac.Xuat();
    cout << "\n";

    // Phóng to đa giác theo tỉ lệ k
    double k;
    cout << "Nhap ti le phong to: ";
    cin >> k;
    daGiac.PhongTo(k);
    cout << "Da giac sau khi phong to:\n";
    daGiac.Xuat();
    cout << "\n";

    // Thu nhỏ đa giác theo tỉ lệ k
    double k2;
    cout << "Nhap ti le thu nho: ";
    cin >> k2;
    daGiac.ThuNho(k2);
    cout << "Da giac sau khi thu nho:\n";
    daGiac.Xuat();

    return 0;
}