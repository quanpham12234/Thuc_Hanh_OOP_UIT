#include "DS_PhanSo.h"
#include <iostream>

using namespace std;

int main()
{
    DSPhanSo ds;

    // Nhập danh sách phân số
    cout << "Nhap danh sach phan so: \n";
    ds.Nhap();

    // Xuất danh sách phân số vừa nhập
    cout << "\nDanh sach phan so vua nhap:\n";
    ds.Xuat();

    // Tính tổng các phân số trong danh sách
    cout << "\nTong cac phan so trong danh sach: " << ds.Tong() << "\n";

    // Tìm phân số lớn nhất và nhỏ nhất trong danh sách
    cout << "Phan so lon nhat trong danh sach: " << ds.LonNhat() << "\n";
    cout << "Phan so nho nhat trong danh sach: " << ds.NhoNhat() << "\n";

    // Tìm phân số có tử là số nguyên tố lớn nhất
    if (ds.TuSoNguyenToLonNhat().getTuSo() != 0) // Kiểm tra nếu có phân số nào có tử là số nguyên tố
        cout << "Phan so co tu la so nguyen to lon nhat: " << ds.TuSoNguyenToLonNhat() << "\n";

    else
        cout << "Khong co phan so nao co tu la so nguyen to.\n";

    // Sắp xếp danh sách phân số theo thứ tự tăng dần
    cout << "\nDanh sach phan so sau khi sap xep tang dan:\n";
    ds.SapXepTangDan();
    ds.Xuat();

    // Sắp xếp danh sách phân số theo thứ tự giảm dần
    cout << "\nDanh sach phan so sau khi sap xep giam dan:\n";
    ds.SapXepGiamDan();
    ds.Xuat();

    return 0;
}