#include "Candidate.h"

using namespace std;

int main() {
    cListCandidate list;

    // Nhập thông tin thí sinh
    list.Nhap();

    // Xuất thông tin thí sinh trong danh sách
    list.Xuat();

    // Xuất thông tin các thí sinh có tổng điểm lớn hơn 15
    cout << "\nDanh sach thi sinh co tong diem hon 15:\n";
    list.Xuat_TS_hon15();

    // Thí sinh cao điểm nhất
    cCandidate maxCandidate = list.Thi_Sinh_Cao_Nhat();
    cout << "\nThi sinh co tong diem cao nhat la: \n" << maxCandidate << "\n\n";

    // Sắp xếp danh sách thí sinh giảm dần theo tổng điểm
    list.Sap_Xep();
    cout << "\nDanh sach thi sinh sau khi sap xep: \n";
    list.Xuat();

    return 0;
}