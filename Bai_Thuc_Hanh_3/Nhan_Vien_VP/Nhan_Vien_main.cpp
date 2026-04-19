#include "Nhan_Vien.h"

using namespace std;

int main() {
    clistNhanVienVP list;

    // Nhập thông tin n nhân viên
    list.Nhap();

    // Xuất thông tin nhân viên trong danh sách
    cout << "\nDanh sach nhan vien:\n";
    list.Xuat();

    // Nhân viên có lương cao nhất
    cNhanVienVP maxLuongNV = list.Nhan_Vien_Luong_Cao_Nhat();
    cout << "\nNhan vien co luong cao nhat la: \n" << maxLuongNV << "\n\n";

    // Tổng lương công ty phải trả cho nhân viên
    double totalSalary = list.Tong_Luong();
    cout << "Tong luong cong ty phai tra cho nhan vien: " << totalSalary << "\n\n";
    
    // Nhân viên lớn tuổi nhất
    cNhanVienVP oldestNV = list.Nhan_Vien_Lon_Tuoi_Nhat();
    cout << "Nhan vien lon tuoi nhat la: \n" << oldestNV << "\n\n";

    // Sắp xếp danh sách nhân viên theo lương tăng dần
    list.Sap_Xep_Luong_Tang_Dan();
    cout << "Danh sach nhan vien sau khi sap xep theo luong tang dan: \n";
    list.Xuat();

    return 0;
}