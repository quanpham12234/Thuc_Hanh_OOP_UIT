#include "CVector.h"

using namespace std;

// Khởi tạo mặc định (vector 0 chiều)
CVector::CVector() : n(0), coords(nullptr) {}

// Khởi tạo vector n chiều, mặc định các tọa độ bằng 0
CVector::CVector(int n)
{
    this->n = (n > 0) ? n : 0;
    if (this->n > 0)
    {
        coords = new double[this->n];
        for (int i = 0; i < this->n; ++i)
        {
            coords[i] = 0;
        }
    }
    else
    {
        coords = nullptr;
    }
}

// Hàm thiết lập sao chép
CVector::CVector(const CVector &other)
{
    n = other.n;
    if (n > 0)
    {
        coords = new double[n];
        for (int i = 0; i < n; ++i)
        {
            coords[i] = other.coords[i];
        }
    }
    else
    {
        coords = nullptr;
    }
}

// Hàm hủy
CVector::~CVector()
{
    if (coords != nullptr)
    {
        delete[] coords;
    }
}

// Toán tử gán
CVector &CVector::operator=(const CVector &other)
{
    if (this != &other)
    {
        delete[] coords; // Xóa vùng nhớ hiện tại
        n = other.n;
        if (n > 0)
        {
            coords = new double[n];
            for (int i = 0; i < n; ++i)
            {
                coords[i] = other.coords[i];
            }
        }
        else
        {
            coords = nullptr;
        }
    }
    return *this;
}

// Toán tử cộng
CVector CVector::operator+(const CVector &other) const
{
    if (n != other.n)
    {
        cout << "[Loi] Khong the cong hai vector khac so chieu!\n"; // Thông báo lỗi nếu số chiều khác nhau
        return CVector();
    }
    CVector result(n);
    for (int i = 0; i < n; ++i)
    {
        result.coords[i] = coords[i] + other.coords[i];
    }
    return result;
}

// Toán tử trừ
CVector CVector::operator-(const CVector &other) const
{
    if (n != other.n)
    {
        cout << "[Loi] Khong the tru hai vector khac so chieu!\n"; // Thông báo lỗi nếu số chiều khác nhau
        return CVector();
    }
    CVector result(n);
    for (int i = 0; i < n; ++i)
    {
        result.coords[i] = coords[i] - other.coords[i];
    }
    return result;
}

// Tích vô hướng
double CVector::operator*(const CVector &other) const
{
    if (n != other.n)
    {
        cout << "[Loi] Khong the tinh tich vo huong hai vector khac so chieu!\n"; // Thông báo lỗi nếu số chiều khác nhau
        return 0;
    }
    double result = 0;
    for (int i = 0; i < n; ++i)
    {
        result += coords[i] * other.coords[i];
    }
    return result;
}

// Nhân vector với một số
CVector CVector::operator*(double scalar) const
{
    CVector result(n);
    for (int i = 0; i < n; ++i)
    {
        result.coords[i] = coords[i] * scalar;
    }
    return result;
}

// Truy xuất tọa độ bằng chỉ số (cho phép thay đổi giá trị)
double &CVector::operator[](int index)
{
    return coords[index];
}

// Nhập vector
istream &operator>>(istream &is, CVector &v)
{
    cout << "Nhap so chieu cua vector: ";
    int new_n;
    is >> new_n;

    if (new_n != v.n)
    {
        delete[] v.coords;
        v.n = (new_n > 0) ? new_n : 0;
        v.coords = (v.n > 0) ? new double[v.n] : nullptr;
    }

    cout << "Nhap " << v.n << " toa do:\n";
    for (int i = 0; i < v.n; ++i)
    {
        cout << "Toa do thu " << i + 1 << ": ";
        is >> v.coords[i];
    }
    return is;
}

// Xuất vector
ostream &operator<<(ostream &os, const CVector &v)
{
    os << "(";
    for (int i = 0; i < v.n; ++i)
    {
        os << v.coords[i];
        if (i < v.n - 1)
            os << ", ";
    }
    os << ")";
    return os;
}

// Lấy số chiều của vector
int CVector::getSize()
{
    return n;
}