#include "CMatrix.h"
#include "../C_Vector/CVector.h" 
#include <iostream>

using namespace std;

int main() {
    CMatrix A, B;

    // 1. Nhập ma trận A và B
    cout << "--- NHAP MA TRAN A ---\n";
    cin >> A;

    cout << "\n--- NHAP MA TRAN B ---\n";
    cin >> B;

    // Hiển thị kết quả vừa nhập
    cout << "\n=====================================\n";
    cout << "Ma tran A:\n" << A;
    cout << "Ma tran B:\n" << B;
    cout << "=====================================\n";

    // 2. Thực hiện các phép toán giữa Ma trận và Ma trận
    cout << "\n[TINH TOAN] Phep toan giua Ma tran va Ma tran:\n";
    CMatrix sum = A + B;
    CMatrix diff = A - B;
    CMatrix product = A * B;

    // Hiển thị kết quả Ma trận
    cout << "\nTong 2 ma tran (A + B):\n" << sum;
    cout << "Hieu 2 ma tran (A - B):\n" << diff;
    cout << "Tich 2 ma tran (A * B):\n" << product;
    cout << "-------------------------------------\n";

    // 3. Thực hiện phép toán giữa Ma trận và Vector
    cout << "\n--- NHAP VECTOR V DE NHAN VOI MA TRAN A ---\n";
    CVector v;
    cin >> v;

    cout << "\nVector v vua nhap: " << v << endl;

    // Tính tích Ma trận x Vector (Kích thước: Ma trận m x n nhân Vector n x 1)
    cout << "\n[TINH TOAN] Phep toan giua Ma tran A va Vector v:\n";
    CVector matVecProduct = A * v; 

    // Hiển thị kết quả Ma trận x Vector
    cout << "Ket qua A * v: " << matVecProduct << "\n\n";

    return 0;
}