#include "DS_PhanSo.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

// Hàm tính ước chung lớn nhất (GCD) để rút gọn phân số
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

// Kiểm tra có phải só nguyên tố không
bool prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// Constructor mặc định cho lớp PhanSo
PhanSo::PhanSo() : tuSo(0), mauSo(1) {}

// Constructor có tham số cho lớp PhanSo
PhanSo::PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau)
{
    if (mauSo == 0)
    {
        throw invalid_argument("Mẫu số không được bằng 0.");
    }
    RutGon(); // Rút gọn phân số ngay sau khi tạo
}

// Hàm nhập phân số
istream &operator>>(istream &in, PhanSo &ps)
{
    do
    {
        cout << "Nhap tu: ";
        in >> ps.tuSo;

        cout << "Nhap mau: ";
        in >> ps.mauSo;

        if (ps.mauSo == 0)
            cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
    } while (ps.mauSo == 0);

    ps.RutGon();

    return in;
}

// Hàm xuất phân số
ostream &operator<<(ostream &out, const PhanSo &ps)
{
    if (ps.tuSo == 0)
        out << 0;

    else if (ps.mauSo == 1)
        out << ps.tuSo;

    else
        out << ps.tuSo << "/" << ps.mauSo;

    return out;
}

// Lấy tử số
int PhanSo::getTuSo() const
{
    return tuSo;
}

// Lấy mẫu số
int PhanSo::getMauSo() const
{
    return mauSo;
}

// Hàm rút gọn phân số
void PhanSo::RutGon()
{
    int gcd = UCLN(tuSo, mauSo);

    tuSo /= gcd;
    mauSo /= gcd;

    ChuanHoaDau();
}

// Hàm chuẩn hóa dấu của phân số
void PhanSo::ChuanHoaDau()
{
    if (mauSo < 0)
    {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

// Hàm cộng hai phân số
PhanSo PhanSo::operator+(const PhanSo &other) const
{
    int tu = this->tuSo * other.mauSo + this->mauSo * other.tuSo;
    int mau = this->mauSo * other.mauSo;

    PhanSo KetQua(tu, mau);

    return KetQua;
}

// Hàm so sánh hai phân số <
bool PhanSo::operator<(const PhanSo &other) const
{
    return (long long)(this->tuSo * other.mauSo) < (long long)(this->mauSo * other.tuSo);
}

// Hàm so sánh hai phân số >
bool PhanSo::operator>(const PhanSo &other) const
{
    return other < *this;
}

// Constructor mặc định cho lớp DSPhanSo
DSPhanSo::DSPhanSo() {} // Vector mặc định là rỗng

// Constructor có tham số của lớp DSPhanSo
DSPhanSo::DSPhanSo(const vector<PhanSo> &danhSach)
{
    this->ds = danhSach;
}

// Hàm nhập danh sách phân số
void DSPhanSo::Nhap()
{
    int size;
    cout << "Nhap so luong phan so cua danh sach: ";
    cin >> size;

    this->ds.resize(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ": \n";
        cin >> this->ds[i];
    }
}

// Hàm xuất danh sách phân số
void DSPhanSo::Xuat() const
{
    int size = this->ds.size();

    for (int i = 0; i < size; i++)
    {
        cout << "Phan so thu " << i + 1 << ": " << ds[i] << "\n";
    }
}

// Tính tổng các phân số trong danh sách
PhanSo DSPhanSo::Tong() const
{
    PhanSo Sum;
    for (const auto &ps : this->ds)
        Sum = Sum + ps;

    return Sum;
}

// Tìm phân số lớn nhất trong danh sách
PhanSo DSPhanSo::LonNhat() const
{
    if (ds.empty())
        return PhanSo(0, 1);

    PhanSo Max = this->ds[0];

    for (const PhanSo &ps : this->ds)
        if (ps > Max)
            Max = ps;

    return Max;
}

// Tìm phân số nhỏ nhất trong danh sách
PhanSo DSPhanSo::NhoNhat() const
{
    if (ds.empty())
        return PhanSo(0, 1);

    PhanSo Min = this->ds[0];

    for (const PhanSo &ps : this->ds)
        if (ps < Min)
            Min = ps;

    return Min;
}

// Tìm phân số có tử là số nguyên tố lớn nhất
PhanSo DSPhanSo::TuSoNguyenToLonNhat() const
{
    bool found = false;
    PhanSo Ans;

    for (const PhanSo &ps : this->ds)
    {
        if (prime(ps.getTuSo()))
        {
            if (found == false || ps.getTuSo() > Ans.getTuSo())
                Ans = ps;

            found = true;
        }
    }

    return Ans;
}

// Sắp xếp danh sách phân số theo thứ tự tăng dần
void DSPhanSo::SapXepTangDan()
{
    sort(this->ds.begin(), this->ds.end());
}

// Sắp xếp danh sách phân số theo thứ tự giảm dần
void DSPhanSo::SapXepGiamDan()
{
    sort(this->ds.begin(), this->ds.end(), greater<PhanSo>());
}
