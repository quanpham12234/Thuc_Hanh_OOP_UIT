#include "Da_Thuc.h"

using namespace std;

int main()
{
    cDaThuc dt1, dt2;

    // Nhập đa thức thứ nhất
    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;
    cout << "\n";

    // Nhập đa thức thứ hai
    cout << "Nhap da thuc thu hai:\n";
    cin >> dt2;
    cout << "\n";

    // Xuất hai đa thức
    cout << "\nDa thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    // Tính giá trị đa thức tại một giá trị x
    double x;
    cout << "\nNhap gia tri x de tinh gia tri da thuc: ";
    cin >> x;
    cout << "Gia tri da thuc thu nhat tai x = " << x << ": " << dt1.TinhGiaTri(x) << endl;
    cout << "Gia tri da thuc thu hai tai x = " << x << ": " << dt2.TinhGiaTri(x) << endl;

    // Cộng và trừ hai đa thức
    cDaThuc tong = dt1 + dt2;
    cDaThuc hieu = dt1 - dt2;

    cout << "\nTong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;

    return 0;
}