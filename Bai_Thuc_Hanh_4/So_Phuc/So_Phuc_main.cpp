#include "So_Phuc.h"
#include <iostream>

using namespace std;

int main() {
    SoPhuc sp1, sp2;

    // Nhập hai số phức từ người dùng
    cout << "Nhap so phuc thu nhat:" << endl;
    cin >> sp1;

    cout << "Nhap so phuc thu hai:" << endl;
    cin >> sp2;

    // Hiển thị hai số phức
    cout << "So phuc thu nhat: " << sp1 << endl;
    cout << "So phuc thu hai: " << sp2 << endl;

    // Thực hiện các phép toán và hiển thị kết quả
    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;

    try {
        cout << "Thuong: " << sp1 / sp2 << endl;
    } catch (const runtime_error &e) { // Bắt lỗi khi chia cho số phức có phần thực và phần ảo đều là 0
        cout << e.what() << endl;
    }

    // So sánh hai số phức
    if (sp1 == sp2) {
        cout << "Hai so phuc bang nhau." << endl;
    } else {
        cout << "Hai so phuc khong bang nhau." << endl;
    }

    return 0;
}