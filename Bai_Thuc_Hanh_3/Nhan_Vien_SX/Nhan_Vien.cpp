#include "Nhan_Vien.h"
#include <iomanip>
#include <algorithm>

using namespace std;

// Toán tử so sánh để so sánh ngày sinh (dùng cho tìm nhân viên lớn tuổi nhất)
bool Date::operator>(const Date &other) const
{
    if (year != other.year)
        return year > other.year;
    if (month != other.month)
        return month > other.month;
    return day > other.day;
}

// Constructor mặc định cho lớp cNhanVienSX
cNhanVienSX::cNhanVienSX()
{
    Id = "";
    Name = "";
    date = {1, 1, 1};
    So_San_Pham = 0;
    Don_Gia = 0.0;
}

// Thao tác get
string cNhanVienSX::getId() const
{
    return Id;
}

string cNhanVienSX::getName() const
{
    return Name;
}

Date cNhanVienSX::getDate() const
{
    return date;
}

int cNhanVienSX::getSoSanPham() const
{
    return So_San_Pham;
}

double cNhanVienSX::getDonGia() const
{
    return Don_Gia;
}

// Thao tác set
void cNhanVienSX::setId(const string &id)
{
    Id = id;
}

void cNhanVienSX::setName(const string &name)
{
    Name = name;
}

void cNhanVienSX::setDate(const Date &date)
{
    this->date = date;
}

void cNhanVienSX::setSoSanPham(int soSanPham)
{
    So_San_Pham = soSanPham;
}

void cNhanVienSX::setDonGia(double donGia)
{
    Don_Gia = donGia;
}

// Nhập thông tin cho nhân viên
istream &operator>>(istream &in, cNhanVienSX &a)
{
    cout << "Nhap ma nhan vien: ";
    in >> a.Id;
    in.ignore();

    cout << "Nhap ho ten: ";
    getline(in, a.Name);

    cout << "Nhap ngay sinh (theo format DD MM YY): ";
    in >> a.date.day >> a.date.month >> a.date.year;

    cout << "Nhap so san pham: ";
    in >> a.So_San_Pham;

    cout << "Nhap don gia: ";
    in >> a.Don_Gia;

    return in;
}

// Xuất thông tin của nhân viên
ostream &operator<<(ostream &out, const cNhanVienSX &a)
{
    // Ghép ngày tháng năm thành 1 chuỗi để dễ căn lề
    string day = (a.date.day < 10 ? "0" : "") + to_string(a.date.day);
    string month = (a.date.month < 10 ? "0" : "") + to_string(a.date.month);
    string dob = day + "/" + month + "/" + to_string(a.date.year);

    // Sử dụng setw() để chia cột
    out << left << setw(12) << a.Id
        << left << setw(22) << a.Name
        << left << setw(14) << dob
        << right << setw(10) << a.So_San_Pham
        << right << setw(12) << fixed << setprecision(2) << a.Don_Gia;

    return out;
}

// Tính lương của nhân viên sản xuất
double cNhanVienSX::Tinh_Luong() const
{
    return So_San_Pham * Don_Gia;
}

// Constructor mặc định cho lớp clistNhanVienSX
clistNhanVienSX::clistNhanVienSX()
{
    // Không cần khởi tạo gì đặc biệt cho vector, nó sẽ tự động quản lý bộ nhớ
}

// Nhập thông tin n nhân viên
void clistNhanVienSX::Nhap()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cNhanVienSX nv;
        cin >> nv;
        list.push_back(nv);
        cout << "\n";
    }
}

// Xuất thông tin nhân viên trong danh sách
void clistNhanVienSX::Xuat()
{
    if (list.empty())
    {
        cout << "Danh sach rong!" << endl;
        return;
    }
    // In tiêu đề bảng
    cout << left << setw(12) << "Ma NV"
         << left << setw(22) << "Ho Ten"
         << left << setw(14) << "Ngay Sinh"
         << right << setw(10) << "So SP"
         << right << setw(12) << "Don Gia" << endl;
    cout << string(70, '-') << endl;
    for (const auto &nv : list)
    {
        cout << nv << endl;
    }
}

// Nhân viên có lương thấp nhất
cNhanVienSX clistNhanVienSX::Nhan_Vien_Luong_Thap_Nhat()
{
    if (list.empty())
    {
        cout << "Danh sach rong!" << endl;
        return cNhanVienSX(); // Trả về một nhân viên mặc định nếu danh sách rỗng
    }

    cNhanVienSX minLuongNV = list[0];
    for (const auto &nv : list)
    {
        if (nv.Tinh_Luong() < minLuongNV.Tinh_Luong())
        {
            minLuongNV = nv;
        }
    }
    return minLuongNV;
}

// Tổng lương công ty phải trả cho nhân viên
double clistNhanVienSX::Tong_Luong()
{
    double total = 0.0;
    for (const auto &nv : list)
    {
        total += nv.Tinh_Luong();
    }
    return total;
}

// Nhân viên lớn tuổi nhất
cNhanVienSX clistNhanVienSX::Nhan_Vien_Lon_Tuoi_Nhat()
{
    if (list.empty())
    {
        cout << "Danh sach rong!" << endl;
        return cNhanVienSX(); // Trả về một nhân viên mặc định nếu danh sách rỗng
    }

    cNhanVienSX oldestNV = list[0];
    for (const auto &nv : list)
    {
        if (oldestNV.getDate() > nv.getDate())
        {
            oldestNV = nv;
        }
    }
    return oldestNV;
}

// Cmp để sắp xếp nhân viên theo lương tăng dần
bool cmpLuong(const cNhanVienSX &a, const cNhanVienSX &b)
{
    return a.Tinh_Luong() < b.Tinh_Luong();
}

// Sắp xếp danh sách nhân viên theo lương tăng dần
void clistNhanVienSX::Sap_Xep_Luong_Tang_Dan()
{
    sort(list.begin(), list.end(), cmpLuong);
}