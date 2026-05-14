#include "c_time.h"
#include <iostream>

using namespace std;

int main() {
    cTime tg1, tg2;

    // Nhập hai thời gian từ người dùng
    cout << "Nhap thoi gian thu nhat:" << endl;
    cin >> tg1;

    cout << "Nhap thoi gian thu hai:" << endl;
    cin >> tg2;

    // Hiển thị hai thời gian
    cout << "Thoi gian thu nhat: " << tg1 << endl;
    cout << "Thoi gian thu hai: " << tg2 << endl;

    // Thực hiện các phép toán và hiển thị kết quả
    cout << "Tong: " << tg1 + tg2 << endl;
    cout << "Hieu: " << tg1 - tg2 << endl;

    // Sử dụng toán tử ++ (tiền tố)
    cout << "Tang thoi gian thu nhat (tien to): " << ++tg1 << endl;

    // Sử dụng toán tử ++ (hậu tố)
    cout << "Tang thoi gian thu hai (hau to): " << tg2++ << endl;
    cout << "Thoi gian thu hai sau khi tang (hau to): " << tg2 << endl;

    return 0;
}
