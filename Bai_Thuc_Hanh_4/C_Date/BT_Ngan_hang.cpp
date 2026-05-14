#include "c_date.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int So_Tien_Goc, Lai_Suat_Nam;
    c_Date Ngay_Vay, Ngay_Tra;

    cout << "Nhap so tien goc: ";
    cin >> So_Tien_Goc;

    cout << "\nNhap lai suat nam(% theo nam): ";
    cin >> Lai_Suat_Nam;

    cout << "\nNhap ngay vay (dd/mm/yyyy):\n";
    cin >> Ngay_Vay;

    cout << "\nNhap ngay tra (dd/mm/yyyy):\n";
    cin >> Ngay_Tra;

    int So_Ngay_Vay = Ngay_Vay.daysBetween(Ngay_Tra);
    double Lai_Suat_Ngay = static_cast<double>(Lai_Suat_Nam) / 365;
    double Tong_Lai = So_Tien_Goc * Lai_Suat_Ngay * So_Ngay_Vay;
    cout << "\nTong lai phai tra: " << fixed << setprecision(2) << Tong_Lai << " dong"<< endl;

    return 0;
}   