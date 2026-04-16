#include "Da_Thuc.h"

#include <cmath>

using namespace std;

// Constructor mặc định có bậc bằng 0
cDaThuc::cDaThuc()
{
    heSo.push_back(0); // Đa thức mặc định là 0
}

// Nhập đa thức
istream &operator>>(istream &in, cDaThuc &a)
{
    int bac;
    cout << "Nhap bac cua da thuc: ";
    in >> bac;
    a.heSo.resize(bac + 1); // Thay đổi kích thước vector để chứa hệ số đến bậc cao nhất
    for (int i = 0; i <= bac; i++)
    {
        cout << "Nhap he so cua x^" << i << ": ";
        in >> a.heSo[i];
    }
    return in;
}

// Xuất đa thức
ostream &operator<<(ostream &out, const cDaThuc &a)
{
    bool first = true;

    for (int i = a.heSo.size() - 1; i >= 0; i--)
    {
        if (a.heSo[i] != 0)
        {
            if (!first)
            {
                if (a.heSo[i] > 0)
                {
                    out << " + ";
                }
                else
                {
                    out << " - ";
                }
            }
            else
            {
                if (a.heSo[i] < 0)
                {
                    out << "-";
                }
            }

            double hs = fabs(a.heSo[i]);
            if (hs != 1 || i == 0)
            {
                out << hs;
            }

            if (i > 1)
            {
                out << "x^" << i;
            }
            else if (i == 1)
            {
                out << "x";
            }

            first = false;
        }
    }
    if (first)
        out << "0";

    return out;
}

// Tính giá trị đa thức khi biết x
double cDaThuc::TinhGiaTri(double x) const
{
    double result = 0.0;

    for (int i = heSo.size() - 1; i >= 0; i--)
    {
        result = result * x + heSo[i]; // Sử dụng thuật toán Horner để tính giá trị đa thức
    }

    return result;
}

// Cộng hai đa thức
cDaThuc cDaThuc::operator+(const cDaThuc &other) const
{
    cDaThuc result;
    int maxSize = max(heSo.size(), other.heSo.size());
    result.heSo.resize(maxSize, 0.0); // Khởi tạo hệ số bằng 0

    for (int i = 0; i < maxSize; i++)
    {
        double hs1 = (i < heSo.size()) ? heSo[i] : 0.0;
        double hs2 = (i < other.heSo.size()) ? other.heSo[i] : 0.0;
        result.heSo[i] = hs1 + hs2;
    }

    while (result.heSo.size() > 1 && result.heSo.back() == 0)
    {
        result.heSo.pop_back(); // Loại bỏ các hệ số bằng 0 ở bậc cao nhất
    }

    return result;
}

// Trừ hai đa thức
cDaThuc cDaThuc::operator-(const cDaThuc &other) const
{
    cDaThuc result;
    int maxSize = max(heSo.size(), other.heSo.size());
    result.heSo.resize(maxSize, 0.0); // Khởi tạo hệ số bằng 0

    for (int i = 0; i < maxSize; i++)
    {
        double hs1 = (i < heSo.size()) ? heSo[i] : 0.0;
        double hs2 = (i < other.heSo.size()) ? other.heSo[i] : 0.0;
        result.heSo[i] = hs1 - hs2;
    }

    while (result.heSo.size() > 1 && result.heSo.back() == 0)
    {
        result.heSo.pop_back(); // Loại bỏ các hệ số bằng 0 ở bậc cao nhất
    }

    return result;
}