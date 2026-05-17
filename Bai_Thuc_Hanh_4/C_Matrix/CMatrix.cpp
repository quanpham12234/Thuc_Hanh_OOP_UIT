#include "CMatrix.h"

// Khởi tạo mặc định
CMatrix::CMatrix() : rows(0), cols(0), data(nullptr) {}

// Khởi tạo ma trận r hàng, c cột
CMatrix::CMatrix(int r, int c) {
    rows = (r > 0) ? r : 0;
    cols = (c > 0) ? c : 0;
    
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    } else {
        data = nullptr;
    }
}

// Copy constructor (Sao chép sâu cho mảng 2 chiều)
CMatrix::CMatrix(const CMatrix& other) {
    rows = other.rows;
    cols = other.cols;
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    } else {
        data = nullptr;
    }
}

// Hàm hủy (Thu hồi từng hàng trước, sau đó thu hồi mảng con trỏ)
CMatrix::~CMatrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// Toán tử gán
CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        // Xóa dữ liệu cũ
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }

        // Cấp phát và chép dữ liệu mới
        rows = other.rows;
        cols = other.cols;
        if (rows > 0 && cols > 0) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new double[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

// Cộng 2 ma trận
CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Hai ma tran khong cung kich thuoc!\n";
        return CMatrix();
    }
    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Trừ 2 ma trận
CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Hai ma tran khong cung kich thuoc!\n";
        return CMatrix();
    }
    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Nhân 2 ma trận (M1 có kích thước m x n, M2 có kích thước n x p)
CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "[Loi] So cot cua ma tran 1 phai bang so hang cua ma tran 2!\n";
        return CMatrix();
    }
    // Ma trận kết quả có kích thước: rows x other.cols
    CMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Nhân Ma trận với Vector (Ma trận m x n nhân Vector n x 1 ra Vector m x 1)
CVector CMatrix::operator*(CVector& v) const {
    if (cols != v.getSize()) {
        cout << "[Loi] So cot ma tran phai bang so chieu cua vector!\n";
        return CVector();
    }
    CVector result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += data[i][j] * v[j];
        }
    }
    return result;
}

// Nhập ma trận
istream& operator>>(istream& is, CMatrix& m) {
    cout << "Nhap so hang: ";
    int r;
    is >> r;
    cout << "Nhap so cot: ";
    int c;
    is >> c;

    // Cấp phát lại nếu kích thước thay đổi
    if (r != m.rows || c != m.cols) {
        if (m.data != nullptr) {
            for (int i = 0; i < m.rows; ++i) delete[] m.data[i];
            delete[] m.data;
        }
        m.rows = (r > 0) ? r : 0;
        m.cols = (c > 0) ? c : 0;
        if (m.rows > 0 && m.cols > 0) {
            m.data = new double*[m.rows];
            for (int i = 0; i < m.rows; ++i) {
                m.data[i] = new double[m.cols];
            }
        } else {
            m.data = nullptr;
        }
    }

    cout << "Nhap cac phan tu cua ma tran (" << m.rows << "x" << m.cols << "):\n";
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            is >> m.data[i][j];
        }
    }
    return is;
}

// Xuất ma trận
ostream& operator<<(ostream& os, const CMatrix& m) {
    if (m.rows == 0 || m.cols == 0) {
        os << "(Ma tran rong)\n";
        return os;
    }
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            os << m.data[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}