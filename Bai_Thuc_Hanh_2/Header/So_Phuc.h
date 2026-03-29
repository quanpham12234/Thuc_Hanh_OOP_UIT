#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc {
private:
    int iThuc;
    int iAo;

public:
    void Nhap();
    void Xuat();

    SoPhuc Tong(SoPhuc sp);
    SoPhuc Hieu(SoPhuc sp);
    SoPhuc Tich(SoPhuc sp);
    SoPhuc Thuong(SoPhuc sp);

};

#endif
