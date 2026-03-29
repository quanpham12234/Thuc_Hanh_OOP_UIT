#ifndef DATE_H
#define DATE_H

class Date{
    private:
    int iNgay;
    int iThang;
    int iNam;

    public:
    void Nhap();
    void Xuat();
    Date NgayThangNamTiepTheo();
};


#endif