#include "Tam_Giac.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

const double eps = 1e-5;

using namespace std;

// Constructor mặc định cho lớp Diem
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
double cTamGiac::DoDai(const Diem &a, const Diem &b) const
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Constructor (hàm tạo)
cTamGiac::cTamGiac()
{
    A = Diem(0.0, 0.0);
    B = Diem(1.0, 0.0);
    C = Diem(0.0, 1.0);
}

cTamGiac::~cTamGiac()
{
    // Không cần làm gì đặc biệt trong destructor
    // Vì chúng ta không sử dụng tài nguyên động (dynamic memory) trong lớp này
}

// Nhập dữ liệu tam giác
void cTamGiac::Nhap()
{
    cout << "Nhap toa do diem A(xA, yA): ";
    cin >> A;

    cout << "Nhap toa do diem B(xB, yB): ";
    cin >> B;

    cout << "Nhap toa do diem C(xC, yC): ";
    cin >> C;
}


// Xác định loại tam giác:
string cTamGiac::LoaiTamGiac()
{
    double c1 = DoDai(A, B);
    double c2 = DoDai(A, C);
    double c3 = DoDai(B, C);
    bool deu = false;
    bool can = false;
    bool vuong = false;

    if (c1 >= c2 + c3 || c2 >= c1 + c3 || c3 >= c1 + c2)
        return "Khong phai tam giac";

    if (abs(c1 - c2) <= eps && abs(c1 - c3) <= eps)
        deu = true;

    if ((abs(c1 - c2) <= eps && abs(c1 - c3) >= eps) ||
        (abs(c1 - c3) <= eps && abs(c1 - c2) >= eps) ||
        (abs(c2 - c3) <= eps && abs(c2 - c1) >= eps))
        can = true;

    if ((abs(pow(c1, 2) + pow(c2, 2) - pow(c3, 2)) <= eps) ||
        (abs(pow(c1, 2) + pow(c3, 2) - pow(c2, 2)) <= eps) ||
        (abs(pow(c3, 2) + pow(c2, 2) - pow(c1, 2)) <= eps))
        vuong = true;

    if (deu) return "Tam giac deu";
    if (can && vuong) return "Tam giac can vuong";
    if (can) return "Tam giac can";
    if (vuong) return "Tam giac vuong";

    return "Tam giac thuong";
}


// Tính chu vi tam giác
double cTamGiac::ChuVi()
{
    double c1 = DoDai(A, B);
    double c2 = DoDai(A, C);
    double c3 = DoDai(B, C);
    return c1 + c2 + c3;
}


// Tính diện tích (dùng công thức Heron)
double cTamGiac::DienTich()
{
    double c1 = DoDai(A, B);
    double c2 = DoDai(A, C);
    double c3 = DoDai(B, C);
    double p = ChuVi() / 2;

    return sqrt(p * (p - c1) * (p - c2) * (p - c3));
}


// Xuất thông tin tam giác
void cTamGiac::Xuat()
{
    cout << "Thong tin tam giac ABC: \n";

    cout << "Toa do diem A: ";
    cout << A << "\n";

    cout << "Toa do diem B: ";
    cout << B << "\n";

    cout << "Toa do diem C: ";
    cout << C << "\n";

    cout << "Loai tam giac: " << LoaiTamGiac() << "\n";

    cout << "Chu vi tam giac: " << ChuVi() << "\n";

    cout << "Dien tich tam giac: " << DienTich() << "\n";
}


// Tịnh tiến tam giác theo vector (dx, dy)
void cTamGiac::TinhTien(double dx, double dy)
{
    A.x += dx;
    A.y += dy;

    B.x += dx;
    B.y += dy;

    C.x += dx;
    C.y += dy;
}


// Quay tam giác quanh gốc tọa độ (0,0) một góc (độ)
void cTamGiac::Quay(double angle)
{
    double rad = angle * M_PI / 180.0; // Chuyển góc từ độ sang radian
    
    auto Rotate = [&] (Diem &p) {
        double newX = p.x * cos(rad) - p.y * sin(rad);
        double newY = p.x * sin(rad) + p.y * cos(rad);
        p.x = newX;
        p.y = newY;
    };

    Rotate(A);
    Rotate(B);
    Rotate(C);
}


// Phóng to tam giác theo tỉ lệ k
void cTamGiac::PhongTo(double k)
{
    if (k <= 0) {
        cout << "Ti le khong hop le. Khong the phong to tam giac.\n";
        return;
    }

    A.x *= k;
    A.y *= k;

    B.x *= k;
    B.y *= k;

    C.x *= k;
    C.y *= k;
}


// Thu nhỏ tam giác theo tỉ lệ k
void cTamGiac::ThuNho(double k)
{
    if (k <= 0) {
        cout << "Ti le khong hop le. Khong the thu nho tam giac.\n";
        return;
    }

    A.x /= k;
    A.y /= k;

    B.x /= k;
    B.y /= k;

    C.x /= k;
    C.y /= k;
}