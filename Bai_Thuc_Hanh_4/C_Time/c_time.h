#ifndef C_TIME_H
#define C_TIME_H

#include <iostream>
using namespace std;

class cTime {
    private:
    int iGio;
    int iPhut;
    int iGiay;

    public:
    // Constructor mặc định
    cTime();

    // Constructor có tham số
    cTime(int gio, int phut, int giay);

    // Chuẩn hoá thời gian
    void chuanHoa();

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, cTime &tg);

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, const cTime &tg);

    // Nạp chồng toán tử +
    cTime operator+(const cTime &tg) const;

    // Nạp chồng toán tử ++ (tiền tố)
    cTime &operator++();

    // Nạp chồng toán tử ++ (hậu tố)
    cTime operator++(int);

    // Nạp chồng toán tử -
    cTime operator-(const cTime &tg) const;

    // Nạp chồng toán tử -- (tiền tố)
    cTime &operator--();

    // Nạp chồng toán tử -- (hậu tố)
    cTime operator--(int);
};

#endif