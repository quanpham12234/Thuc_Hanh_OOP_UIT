#include "Candidate.h"
#include <algorithm>
#include <iomanip>

using namespace std;

// Hàm để in tiêu đề bảng
void InTieuDeBang() {
    cout << string(74, '-') << "\n";
    cout << left << setw(12) << "Ma TS" 
         << left << setw(22) << "Ho va ten" 
         << left << setw(14) << "Ngay sinh" 
         << right << setw(6) << "Toan" 
         << right << setw(6) << "Van" 
         << right << setw(6) << "Anh" 
         << right << setw(8) << "Tong" << "\n";
    cout << string(74, '-') << "\n";
}

// Constructor mặc định cho lớp cCandidate
cCandidate::cCandidate()
{
    ID = "";
    Name = "";
    date = {1, 1, 1};
    Toan = 1, Van = 1, Anh = 1;
}

// Nhập thông tin cho thí sinh
istream &operator>>(istream &in, cCandidate &a)
{
    cout << "Nhap ma thi sinh: ";
    in >> a.ID;
    in.ignore();

    cout << "Nhap ho ten: ";
    getline(in, a.Name);

    cout << "Nhap ngay sinh (theo format DD MM YY): ";
    in >> a.date.day >> a.date.month >> a.date.year;

    cout << "Nhap diem toan: ";
    in >> a.Toan;

    cout << "Nhap diem van: ";
    in >> a.Van;

    cout << "Nhap diem anh: ";
    in >> a.Anh;

    return in;
}

// Xuất thông tin của thí sinh
ostream &operator<<(ostream &out, const cCandidate &a)
{
    // Ghép ngày tháng năm thành 1 chuỗi để dễ căn lề
    string day = (a.date.day < 10 ? "0" : "") + to_string(a.date.day);
    string month = (a.date.month < 10 ? "0" : "") + to_string(a.date.month);
    string dob = day + "/" + month + "/" + to_string(a.date.year);

    // Sử dụng setw() để chia cột
    out << left << setw(12) << a.ID
        << left << setw(22) << a.Name
        << left << setw(14) << dob
        << right << setw(6) << a.Toan
        << right << setw(6) << a.Van
        << right << setw(6) << a.Anh
        << right << setw(8) << a.Tong_3_mon();

    return out;
}

// Tổng điểm 3 môn
double cCandidate::Tong_3_mon() const
{
    return Toan + Van + Anh;
}

// Constructor mặc định cho lớp cListCandidate
cListCandidate::cListCandidate()
{
}

// Nhập thông tin n người dùng
void cListCandidate::Nhap()
{
    int size;
    cout << "Nhap so luong thi sinh: ";
    cin >> size;

    list.resize(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ": \n";
        cin >> list[i];
        cout << "\n";
    }
}

// Xuất thông tin thí sinh trong danh sách
void cListCandidate::Xuat()
{
    if (list.empty()) {
        cout << "Danh sach trong!\n";
        return;
    }
    
    InTieuDeBang();
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }
    cout << string(74, '-') << "\n";
}

// Thí sinh có tổng điểm lớn hơn 15
void cListCandidate::Xuat_TS_hon15()
{
    if (list.empty()) return;

    bool found = false;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].Tong_3_mon() > 15) {
            if (!found) {
                // Chỉ in tiêu đề bảng 1 lần nếu tìm thấy ít nhất 1 người
                InTieuDeBang(); 
                found = true;
            }
            cout << list[i] << "\n";
        }
    }
    
    if (found) cout << string(74, '-') << "\n";
    else cout << "Khong co thi sinh nao co tong diem lon hon 15!\n";
}

// Thí sinh cao điểm nhất
cCandidate cListCandidate::Thi_Sinh_Cao_Nhat()
{
    if (list.empty())
    {
        cout << "Khong co thi sinh nao! \n";
        return cCandidate();
    }

    cCandidate maxCandidate = list[0];
    for (const auto &candidate : list)
    {
        if (candidate.Tong_3_mon() > maxCandidate.Tong_3_mon())
        {
            maxCandidate = candidate;
        }
    }
    return maxCandidate;
}

// Comparator để sắp xếp thí sinh giảm dần theo tổng điểm
bool cmp(const cCandidate &a, const cCandidate &b)
{
    return a.Tong_3_mon() > b.Tong_3_mon();
}

// Sắp xếp danh sách thí sinh giảm dần theo tổng điểm
void cListCandidate::Sap_Xep()
{
    sort(list.begin(), list.end(), cmp);
}