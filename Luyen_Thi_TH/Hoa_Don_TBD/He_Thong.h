#ifndef HE_THONG_H
#define HE_THONG_H

#include <iostream>
using namespace std;

// Cấu trúc Date để lưu ngày tháng năm
struct Date {
    int day;
    int month;
    int year;
};

enum Loai_TB_Dien {Quat, May_Lanh};
enum Loai_Quat {Dung, Hoi_Nuoc, Dien};
enum Loai_May_Lanh {Mot_Chieu, Hai_Chieu};

class E_Devices {
    private:
    string MaSP; // Mã sản phẩm
    string TenSP; // Tên sản phẩm
    string NSX; // Nơi sản xuất
    Loai_TB_Dien TypeTB; // Loại thiết bị : Quạt, Máy lạnh

    public:
    // Constructor mặc định cho Class Thiết bị điện
    E_Devices();

    // Virtual Destructor cho Class Thiết bị điện
    virtual ~E_Devices() = 0;

    // Phương thức ảo cho hàm nhập (2 loại Thiết bị điện)
    virtual void input();

    // Phương thức ảo cho hàm xuất
    virtual void output() = 0;

    // Hàm Get MaSP
    string getMaSP();

    // Hàm Get TenSP
    string getTenSP();

    // Phương thức ảo Get GiaBan, bởi vì có 2 loại Thiết bị điện
    virtual double getGiaBan() = 0;

    // Hàm Get NuocSX
    string getNuocSX();

    // Hàm Set TypeTB
    void setTypeTB(int type);
};

class Fan_Devices : public E_Devices {
    private:
    Loai_Quat TypeFan; // Loại quạt: Quạt đứng, Quạt hơi nước, Quạt đi

    public:
    // Virtual Destructor của Fan_Devices
    virtual ~Fan_Devices() = 0;

    // Phương thức ảo cho hàm nhập (3 loại quạt)
    virtual void input();

    // Phương thức ảo cho hàm xuất (3 loại quạt)
    virtual void output();

    // Phương thức ảo Get GiaBan (3 loại quạt)
    virtual double getGiaBan() = 0;
};

class Quat_Dung: public Fan_Devices {
    public:
    // Hàm nhập cho Lớp Quạt Đứng
    void input();

    // Hàm xuất cho Lớp Quạt Đứng
    void output();

    // Hàm lấy Giá Bán cho Lớp Quạt Đứng
    double getGiaBan();
};

class Quat_Hoi_Nuoc: public Fan_Devices {
    private:
    double Dung_Tich_TD; // Dung tích nước tối đa (lít)

    public:
    // Hàm nhập cho Lớp Quạt Hơi Nước
    void input();

    // Hàm xuất cho Lớp Quạt Hơi Nước
    void output();

    // Hàm xuất cho Lớp Quạt Hơi Nước
    double getGiaBan();
};

class Quat_Dien: public Fan_Devices {
    private:
    double Dung_Luong_Pin; // Dung lượng pin 

    public:
    // Hàm nhập cho Lớp Quạt Điện
    void input();

    // Hàm xuất cho Lớp Quạt Điện
    void output();

    // Hàm xuất cho Lớp Quạt Điện
    double getGiaBan();
};

class Air_Conditioner : public E_Devices {
    private:
    Loai_May_Lanh TypeAC; // Loại máy lạnh: Một chiều, Hai chiều
    bool hasInverter; // Có công nghệ Inverter hay không

    public:
    // Virtual Destructor của Air_Conditioner
    virtual ~Air_Conditioner() = 0;

    // Hàm nhập cho Lớp Máy Lạnh
    virtual void input();

    // Hàm xuất cho Lớp Máy Lạnh
    virtual void output();

    // Hàm lấy Giá Bán cho Lớp Máy Lạnh
    virtual double getGiaBan();
};

class May_Lanh_Mot_Chieu : public Air_Conditioner {
    public:
    // Hàm nhập cho Lớp Máy Lạnh Một Chiều
    void input();

    // Hàm xuất cho Lớp Máy Lạnh Một Chiều
    void output();

    // Hàm lấy Giá Bán cho Lớp Máy Lạnh Một Chiều
    double getGiaBan();
};

class May_Lanh_Hai_Chieu : public Air_Conditioner {
    public:
    // Hàm nhập cho Lớp Máy Lạnh Hai Chiều
    void input();

    // Hàm xuất cho Lớp Máy Lạnh Hai Chiều
    void output();

    // Hàm lấy Giá Bán cho Lớp Máy Lạnh Hai Chiều
    double getGiaBan();
};

#endif