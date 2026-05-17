#include "CVector.h"
#include <iostream>

using namespace std;

int main() {
    CVector v1, v2;

    // Nhập hai vector v1 và v2 từ người dùng
    cout << "Nhap vector thu nhat:\n";
    cin >> v1;

    cout << "Nhap vector thu hai:\n";
    cin >> v2;

    // Hiển thị kết quả
    cout << "\nVector thu nhat: " << v1 << endl;
    cout << "Vector thu hai: " << v2 << endl;

    // Thực hiện các phép toán giữa hai vector
    CVector sum = v1 + v2;
    CVector diff = v1 - v2;
    double dotProduct = v1 * v2;

    // Hiển thị kết quả
    cout << "\nTong 2 vector: " << sum << endl;
    cout << "Hieu 2 vector: " << diff << endl;
    cout << "Tich vo huong (dot product) 2 vector: " << dotProduct << endl;

    return 0;
}