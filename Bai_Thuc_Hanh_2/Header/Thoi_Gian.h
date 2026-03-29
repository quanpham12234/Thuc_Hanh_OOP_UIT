#ifndef THOIGIAN_H
#define THOIGIAN_H

class ThoiGian {
    private:
    int iGio;
    int iPhut;
    int iGiay;

    public:
    void Nhap();
    void Xuat();
    
    ThoiGian TinhCongThemMotGiay();
};

#endif