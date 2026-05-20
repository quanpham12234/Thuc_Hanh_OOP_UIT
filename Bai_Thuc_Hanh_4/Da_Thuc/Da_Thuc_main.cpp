#include <iostream>
#include "Da_Thuc.h"

using namespace std;

int main() {
    DaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;

    cout << "Nhap da thuc thu hai:\n";
    cin >> dt2;

    cout << "\nDa thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    DaThuc tong = dt1 + dt2;
    DaThuc hieu = dt1 - dt2;

    cout << "\nTong 2 da thuc: " << tong << endl;
    cout << "Hieu 2 da thuc: " << hieu << endl;

    double x;
    cout << "\nNhap gia tri x de tinh P(x) cho da thuc thu nhat: ";
    cin >> x;
    cout << "P(" << x << ") = " << dt1(x) << endl;
    
    return 0;
}