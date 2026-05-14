#include "Phan_So.h"
#include <iostream>

using namespace std;

int main() {
    PhanSo ps1, ps2;

    // Nhập hai phân số từ người dùng
    cout << "Nhap phan so thu nhat:" << endl;
    cin >> ps1;

    cout << "Nhap phan so thu hai:" << endl;
    cin >> ps2;

    // Hiển thị hai phân số
    cout << "Phan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;

    // Thực hiện các phép toán và hiển thị kết quả
    cout << "Tong: " << ps1 + ps2 << endl;
    cout << "Hieu: " << ps1 - ps2 << endl;
    cout << "Tich: " << ps1 * ps2 << endl;

    try {
        cout << "Thuong: " << ps1 / ps2 << endl;
    } catch (const runtime_error &e) { // Bắt lỗi khi chia cho phân số có tử số và mẫu số đều là 0
        cout << e.what() << endl;
    }

    // So sánh hai phân số
    if (ps1 == ps2) {
        cout << "Hai phan so bang nhau." << endl;
    } else if (ps1 > ps2) {
        cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
    } else {
        cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
    }

    return 0;
}