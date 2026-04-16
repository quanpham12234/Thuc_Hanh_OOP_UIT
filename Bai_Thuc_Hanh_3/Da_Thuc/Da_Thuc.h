#ifndef DA_THUC_H
#define DA_THUC_H

#include <iostream>
#include <vector>

using namespace std;

class cDaThuc
{
    private:
    vector<double> heSo; // heSo[i] là hệ số của x^i

    public:
    // Constructor mặc định có bậc bằng 0
    cDaThuc();

    // Nhập đa thức
    friend istream &operator>>(istream &in, cDaThuc &a);

    // Xuất đa thức
    friend ostream &operator<<(ostream &out, const cDaThuc &dt);

    // Tính giá trị đa thức khi biết x
    double TinhGiaTri(double x) const;

    // Cộng hai đa thức
    cDaThuc operator+ (const cDaThuc &other) const;

    // Trừ hai đa thức
    cDaThuc operator- (const cDaThuc &other) const;
};  

#endif 