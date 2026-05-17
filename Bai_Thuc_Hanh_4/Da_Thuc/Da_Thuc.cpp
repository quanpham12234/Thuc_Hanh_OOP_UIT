#include "Da_Thuc.h"
#include <cmath>
#include <algorithm>

using namespace std;

// Khởi tạo mặc định
DaThuc::DaThuc() : bac(0)
{
    heSo = new double[1];
    heSo[0] = 0;
}

// Khởi tạo với bậc b cho trước
DaThuc::DaThuc(int b)
{
    bac = (b >= 0) ? b : 0;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i)
    {
        heSo[i] = 0;
    }
}

// Copy constructor (Cần thiết khi dùng mảng động)
DaThuc::DaThuc(const DaThuc &other)
{
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i)
    {
        heSo[i] = other.heSo[i];
    }
}

// Hàm hủy (Giải phóng bộ nhớ)
DaThuc::~DaThuc()
{
    delete[] heSo;
}

// Toán tử gán (Cũng cần thiết để tránh memory leak khi gán A = B)
DaThuc &DaThuc::operator=(const DaThuc &other)
{
    if (this != &other)
    {                  // Tránh gán cho chính nó (A = A)
        delete[] heSo; // Xóa vùng nhớ cũ
        bac = other.bac;
        heSo = new double[bac + 1]; // Cấp phát vùng nhớ mới
        for (int i = 0; i <= bac; ++i)
        {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}

// Toán tử cộng 2 đa thức
DaThuc DaThuc::operator+(const DaThuc &other) const
{
    int maxBac = max(bac, other.bac);
    DaThuc tong(maxBac); // Tạo đa thức mới có bậc lớn nhất

    for (int i = 0; i <= maxBac; ++i)
    {
        double heSo1 = (i <= bac) ? heSo[i] : 0;
        double heSo2 = (i <= other.bac) ? other.heSo[i] : 0;
        tong.heSo[i] = heSo1 + heSo2;
    }
    return tong;
}

// Toán tử trừ 2 đa thức
DaThuc DaThuc::operator-(const DaThuc &other) const
{
    int maxBac = max(bac, other.bac);
    DaThuc hieu(maxBac);

    for (int i = 0; i <= maxBac; ++i)
    {
        double heSo1 = (i <= bac) ? heSo[i] : 0;
        double heSo2 = (i <= other.bac) ? other.heSo[i] : 0;
        hieu.heSo[i] = heSo1 - heSo2;
    }
    return hieu;
}

// Tính giá trị đa thức tại điểm x (VD: P(2))
double DaThuc::operator()(double x) const
{
    double result = 0;
    for (int i = 0; i <= bac; ++i)
    {
        result += heSo[i] * pow(x, i);
    }
    return result;
}

// Toán tử nhập
istream &operator>>(istream &is, DaThuc &dt)
{
    cout << "Nhap bac cua da thuc: ";
    int b;
    is >> b;

    // Nếu bậc mới khác bậc cũ, cần cấp phát lại bộ nhớ
    if (b != dt.bac)
    {
        delete[] dt.heSo;
        dt.bac = (b >= 0) ? b : 0;
        dt.heSo = new double[dt.bac + 1];
    }

    cout << "Nhap cac he so tu bac 0 den bac " << dt.bac << ":\n";
    for (int i = 0; i <= dt.bac; ++i)
    {
        cout << "He so cua x^" << i << ": ";
        is >> dt.heSo[i];
    }
    return is;
}

// Toán tử xuất
ostream &operator<<(ostream &os, const DaThuc &dt)
{
    bool isZero = true;
    for (int i = dt.bac; i >= 0; --i)
    {
        if (dt.heSo[i] != 0)
        {
            isZero = false;
            // In dấu
            if (dt.heSo[i] > 0 && i != dt.bac)
                os << " + ";
            else if (dt.heSo[i] < 0)
            {
                os << (i == dt.bac ? "-" : " - ");
            }

            // In hệ số
            double absHeSo = abs(dt.heSo[i]);
            if (absHeSo != 1 || i == 0)
                os << absHeSo;

            // In x^i
            if (i > 0)
            {
                os << "x";
                if (i > 1)
                    os << "^" << i;
            }
        }
    }
    if (isZero)
        os << "0";
    return os;
}