#include "c_date.h"
#include <iostream>

using namespace std;

int main() {
    c_Date date1, date2;

    // Nhập hai ngày từ người dùng
    cout << "Nhap ngay thu nhat:" << endl;
    cin >> date1;

    cout << "Nhap ngay thu hai:" << endl;
    cin >> date2;

    // Hiển thị hai ngày
    cout << "Ngay thu nhat: " << date1 << endl;
    cout << "Ngay thu hai: " << date2 << endl;

    // Thực hiện các phép toán và hiển thị kết quả
    cout << "Ngay thu nhat sau khi cong 5 ngay: " << date1 + 5 << endl;
    cout << "Ngay thu hai sau khi tru 3 ngay: " << date2 - 3 << endl;

    // Sử dụng toán tử ++ (tiền tố)
    cout << "Tang ngay thu nhat (tien to): " << ++date1 << endl;

    // Sử dụng toán tử ++ (hậu tố)
    cout << "Tang ngay thu hai (hau to): " << date2++ << endl;
    cout << "Ngay thu hai sau khi tang (hau to): " << date2 << endl;

    // Sử dụng toán tử -- (tiền tố)
    cout << "Giam ngay thu nhat (tien to): " << --date1 << endl;
    
    // Sử dụng toán tử -- (hậu tố)
    cout << "Giam ngay thu hai (hau to): " << date2-- << endl;
    cout << "Ngay thu hai sau khi giam (hau to): " << date2 << endl;

    return 0;
}