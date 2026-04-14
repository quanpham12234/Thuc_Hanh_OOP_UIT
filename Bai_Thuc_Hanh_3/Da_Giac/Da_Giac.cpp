#include "Da_Giac.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// Constructor mac định cho lớp Diem
Diem::Diem() : x(0), y(0) {}

// Constructor có 2 tham số x1, y1 cho lớp Diem
Diem::Diem(double x1, double y1) : x(x1), y(y1) {}

// Khoảng cách tới gốc tọa độ
double Diem::KhoachangToiGoc() const
{
    return sqrt(x * x + y * y);
}

// Nạp chồng toán tử nhập (cin >>)
istream &operator>>(istream &in, Diem &a)
{
    in >> a.x >> a.y;
    return in;
}

// Nạp chồng toán tử xuất (cout <<)
ostream &operator<<(ostream &out, const Diem &a)
{
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

// Tính độ dài giữa hai điểm a và b
double cDaGiac::DoDai(const Diem &a, const Diem &b) const
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Constructor (hàm tạo) cho lớp cDaGiac
cDaGiac::cDaGiac() {} // Vector mặc định là rỗng

// Destructor (hàm hủy) cho lớp cDaGiac
cDaGiac::~cDaGiac()
{
    // Không cần làm gì đặc biệt trong destructor
    // Vì chúng ta không sử dụng tài nguyên động (dynamic memory) trong lớp này
}

// Nhập dữ liệu đa giác
void cDaGiac::Nhap()
{
    int n;
    do
    {
        cout << "Nhap so luong dinh cua da giac: ";
        cin >> n;

        if (n < 3)
            cout << "Da giac phai co it nhat 3 dinh! Vui long nhap lai. \n";
    } while (n < 3);
    a.resize(n); // Thay đổi kích thước vector để chứa n điểm

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap toa do dinh " << i + 1 << ": ";
        cin >> a[i];
    }
}

// Tính chu vi đa giác
double cDaGiac::ChuVi() const
{
    double chuVi = 0.0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        chuVi += DoDai(a[i], a[(i + 1) % n]); // Kết nối điểm cuối với điểm đầu
    }
    return chuVi;
}

// Tính diện tích (dùng công thức Shoelace)
double cDaGiac::DienTich() const
{
    double sum = 0.0;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        sum += (a[i].x * a[(i + 1) % n].y - a[(i + 1) % n].x * a[i].y);
    }
    return abs(sum) / 2.0;
}

// Xuất thông tin đa giác
void cDaGiac::Xuat() const
{
    cout << "Thong tin da giac: \n";
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << "Dinh " << i + 1 << ": " << a[i] << "\n";
    }
    cout << "Chu vi da giac: " << ChuVi() << "\n";
    cout << "Dien tich da giac: " << DienTich() << "\n";
}

// Tịnh tiến đa giác theo vector (dx, dy)
void cDaGiac::TinhTien(double dx, double dy)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        a[i].x += dx;
        a[i].y += dy;
    }
}

// Quay đa giác quanh gốc tọa độ (0,0) một góc (độ)
void cDaGiac::Quay(double angle)
{
    double rad = angle * M_PI / 180.0;

    auto Rotate = [&](Diem &p)
    {
        double newX = p.x * cos(rad) - p.y * sin(rad);
        double newY = p.x * sin(rad) + p.y * cos(rad);
        p.x = newX;
        p.y = newY;
    };

    int n = a.size();
    for (int i = 0; i < n; i++)
        Rotate(a[i]);
}

// Phóng to đa giác theo tỉ lệ k
void cDaGiac::PhongTo(double k)
{
    if (k <= 0)
    {
        cout << "Ti le khong hop le. Khong the phong to da giac.\n";
        return;
    }

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        a[i].x *= k;
        a[i].y *= k;
    }
}

// Thu nhỏ đa giác theo tỉ lệ k
void cDaGiac::ThuNho(double k)
{
    if (k <= 0)
    {
        cout << "Ti le khong hop le. Khong the phong to da giac.\n";
        return;
    }

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        a[i].x /= k;
        a[i].y /= k;
    }
}