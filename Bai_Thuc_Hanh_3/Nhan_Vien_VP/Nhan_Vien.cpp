#include "Nhan_Vien.h"

#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

// Toán tử so sánh để so sánh ngày sinh (dùng cho tìm nhân viên lớn tuổi nhất)
bool Date::operator>(const Date &other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

// Constructor mặc định cho lớp cNhanVienVP
cNhanVienVP::cNhanVienVP() {
    Id = "";
    Name = "";
    date = {1, 1, 1};
    Salary = 0.0;
}

// Thao tác get
string cNhanVienVP::getId() const {
    return Id;
}

string cNhanVienVP::getName() const {
    return Name;
}

Date cNhanVienVP::getDate() const {
    return date;
}

double cNhanVienVP::getSalary() const {
    return Salary;
}


// Thao tác set
void cNhanVienVP::setId(const string &id) {
    Id = id;
}

void cNhanVienVP::setName(const string &name) {
    Name = name;
}

void cNhanVienVP::setDate(const Date &date) {
    this->date = date;
}

void cNhanVienVP::setSalary(double salary) {
    Salary = salary;
}


// Nhập thông tin cho nhân viên
istream &operator>>(istream &in, cNhanVienVP &a) { 
    cout << "Nhap ma nhan vien: ";
    in >> a.Id;
    in.ignore();

    cout << "Nhap ho ten: ";
    getline(in, a.Name);

    cout << "Nhap ngay sinh (theo format DD MM YY): ";
    in >> a.date.day >> a.date.month >> a.date.year;

    cout << "Nhap luong: ";
    in >> a.Salary;

    return in;
}

// Xuất thông tin của nhân viên
ostream &operator<<(ostream &out, const cNhanVienVP &a) {
    // Ghép ngày tháng năm thành 1 chuỗi để dễ căn lề
    string day = (a.date.day < 10 ? "0" : "") + to_string(a.date.day);
    string month = (a.date.month < 10 ? "0" : "") + to_string(a.date.month);
    string dob = day + "/" + month + "/" + to_string(a.date.year);

    // Sử dụng setw() để chia cột
    out << left << setw(12) << a.Id
        << left << setw(22) << a.Name
        << left << setw(14) << dob
        << right << setw(10) << fixed << setprecision(2) << a.Salary;

    return out;
}


// Constructor mặc định cho lớp clistNhanVienVP
clistNhanVienVP::clistNhanVienVP() {
    // Không cần làm gì trong constructor mặc định vì vector sẽ tự động khởi tạo
}


// Nhập thông tin n nhân viên
void clistNhanVienVP::Nhap() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); // Xóa bỏ ký tự newline sau khi nhập số

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << (i + 1) << ":\n";
        cNhanVienVP nv;
        cin >> nv;
        list.push_back(nv);
    }
}

// Xuất thông tin nhân viên trong danh sách
void clistNhanVienVP::Xuat() {
    if (list.empty()) {
        cout << "Danh sach nhan vien trong!\n";
        return;
    }

    // In tiêu đề bảng
    cout << left << setw(12) << "Ma NV"
         << left << setw(22) << "Ho Ten"
         << left << setw(14) << "Ngay Sinh"
         << right << setw(10) << "Luong" << "\n";
    cout << string(58, '-') << "\n";

    // In thông tin từng nhân viên
    for (const auto &nv : list) {
        cout << nv << "\n";
    }
    cout << string(58, '-') << "\n";
}

// Nhân viên có lương cao nhất
cNhanVienVP clistNhanVienVP::Nhan_Vien_Luong_Cao_Nhat() {
    if (list.empty()) {
        cout << "Danh sach nhan vien rong!\n";
        return cNhanVienVP(); // Trả về một nhân viên mặc định nếu danh sách rỗng
    }

    cNhanVienVP maxLuongNV = list[0];
    for (const auto &nv : list) {
        if (nv.getSalary() > maxLuongNV.getSalary()) {
            maxLuongNV = nv;
        }
    }
    return maxLuongNV;
}

// Tổng lương công ty phải trả cho nhân viên
double clistNhanVienVP::Tong_Luong() {
    double total = 0.0;
    for (const auto &nv : list) {
        total += nv.getSalary();
    }
    return total;
}

// Nhân viên lớn tuổi nhất
cNhanVienVP clistNhanVienVP::Nhan_Vien_Lon_Tuoi_Nhat() {
    if (list.empty()) {
        cout << "Danh sach nhan vien rong!\n";
        return cNhanVienVP(); // Trả về một nhân viên mặc định nếu danh sách rỗng
    }

    cNhanVienVP oldestNV = list[0];
    for (const auto &nv : list) {
        if (oldestNV.getDate() > nv.getDate()) {
            oldestNV = nv;
        }
    }
    return oldestNV;
}

// Cmp để sắp xếp nhân viên theo lương tăng dần
bool cmpLuong(const cNhanVienVP &a, const cNhanVienVP &b) {
    return a.getSalary() < b.getSalary();
}

// Sắp xếp danh sách nhân viên theo lương tăng dần
void clistNhanVienVP::Sap_Xep_Luong_Tang_Dan() {
    sort(list.begin(), list.end(), cmpLuong);
}