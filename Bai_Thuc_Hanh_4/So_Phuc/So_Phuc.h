#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int iThuc;
    int iAo;

public:
    // Constructor
    SoPhuc();

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, SoPhuc &sp);

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, const SoPhuc &sp);

    // Nạp chồng toán tử +, -, *, /, == , !=
    SoPhuc operator+(const SoPhuc &sp) const;
    SoPhuc operator-(const SoPhuc &sp) const;
    SoPhuc operator*(const SoPhuc &sp) const;
    SoPhuc operator/(const SoPhuc &sp) const;
    bool operator==(const SoPhuc &sp) const;
    bool operator!=(const SoPhuc &sp) const;
};

#endif
