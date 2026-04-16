#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Cấu trúc để lưu ngày sinh
struct Date
{
    int day, month, year;
};

// Lớp cCandidate để lưu thông tin thí sinh
class cCandidate
{
private:
    string ID;
    string Name;
    Date date;
    double Toan, Van, Anh;

public:
    // Constructor mặc định cho lớp cCandidate
    cCandidate();

    // Nhập thông tin
    friend istream &operator>>(istream &in, cCandidate &a);

    // Xuất thông tin
    friend ostream &operator<<(ostream &out, const cCandidate &a);

    // Tổng điểm 3 môn
    double Tong_3_mon() const;
};

// Lớp cListCandidate để quản lý danh sách thí sinh
class cListCandidate
{
private:
    vector<cCandidate> list; // Sử dụng vector để lưu danh sách thí sinh

public:
    // Constructor mặc định cho lớp cListCandidate
    cListCandidate();

    // Nhập thông tin n người dùng
    void Nhap();

    // Xuất thông tin thí sinh trong danh sách
    void Xuat();

    // Xuất thông tin các thí sinh có tổng điểm lớn hơn 15
    void Xuat_TS_hon15();

    // Thí sinh cao diểm nhất
    cCandidate Thi_Sinh_Cao_Nhat();

    // Sắp xếp danh sách thí sinh giảm dần theo tổng điểm
    void Sap_Xep();
};

#endif