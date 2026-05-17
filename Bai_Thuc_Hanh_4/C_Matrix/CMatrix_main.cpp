#include "CMatrix.h"
#include <iostream>

using namespace std;

int main() {
    CMatrix A, B;

    // Nhập hai ma trận A và B từ người dùng
    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "Nhap ma tran B:\n";
    cin >> B;

    // Hiển thị kết quả
    cout << "\nMa tran A:\n" << A;
    cout << "Ma tran B:\n" << B;

    // Thực hiện các phép toán giữa hai ma trận
    CMatrix sum = A + B;
    CMatrix diff = A - B;
    CMatrix product = A * B;

    // Hiển thị kết quả
    cout << "\nTong 2 ma tran:\n" << sum;
    cout << "Hieu 2 ma tran:\n" << diff;
    cout << "Tich 2 ma tran:\n" << product;

    return 0;
}