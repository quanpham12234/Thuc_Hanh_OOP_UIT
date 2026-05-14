#ifndef C_DATE_H
#define C_DATE_H

#include <iostream>

using namespace std;

class c_Date {
    private:
    int iNgay;
    int iThang;
    int iNam;
    
    // Hàm chuyển đổi ngày thành số ngày kể từ một mốc thời gian (ví dụ: 01/01/0000)
    int toDays() const;

    public:
    // Constructor mặc định
    c_Date();

    // Constructor có tham số
    c_Date(int ngay, int thang, int nam);

    // Chuẩn hóa ngày tháng năm
    void chuanHoa();

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, c_Date &date);

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, const c_Date &date);

    // Nạp chồng toán tử +
    c_Date operator+(int days) const;

    // Nạp chồng toán tử ++ (tiền tố)
    c_Date &operator++();

    // Nạp chồng toán tử ++ (hậu tố)
    c_Date operator++(int);

    // Nạp chồng toán tử -
    c_Date operator-(int days) const;

    // Nạp chồng toán tử -- (tiền tố)
    c_Date &operator--();

    // Nạp chồng toán tử -- (hậu tố)
    c_Date operator--(int);

    // Hàm tính số ngày giữa 2 thời gian
    int daysBetween(const c_Date &other) const;
};


#endif