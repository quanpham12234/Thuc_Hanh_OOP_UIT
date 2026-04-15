#include "Mang.h"
#include <iostream>
#include <random>
#include <ctime>
#include <climits>


int main() {
    srand(time(nullptr)); // Khởi tạo seed cho hàm rand() để tạo số ngẫu nhiên khác nhau mỗi lần chạy
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    cArray myArray(n);

    cout << "\nMang ngau nhien:\n";
    myArray.Xuat();

    int x;
    cout << "\nNhap gia tri x de dem so lan xuat hien: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang: " << myArray.DemSoLanXuatHien(x) << "\n";

    if (myArray.KiemTraTangDan())
        cout << "Mang tang dan.\n";
    else
        cout << "Mang khong tang dan.\n";

    int leNhoNhat = myArray.TimLeNhoNhat();
    if (leNhoNhat != INT_MAX)
        cout << "Phan le nho nhat trong mang: " << leNhoNhat << "\n";
    else
        cout << "Khong co phan le nao trong mang.\n";

    int nguyenToLonNhat = myArray.TimNguyenToLonNhat();
    if (nguyenToLonNhat != INT_MIN)
        cout << "So nguyen to lon nhat trong mang: " << nguyenToLonNhat << "\n";
    else
        cout << "Khong co so nguyen to nao trong mang.\n";

    myArray.SapXepTangDan();
    cout << "\nMang sau khi sap xep tang dan:\n";
    myArray.Xuat();

    myArray.SapXepGiamDan();
    cout << "\nMang sau khi sap xep giam dan:\n";
    myArray.Xuat();

    return 0;
}