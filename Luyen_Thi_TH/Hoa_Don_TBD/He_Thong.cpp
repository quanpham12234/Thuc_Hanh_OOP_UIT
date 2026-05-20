#include "He_Thong.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Construtor của Abstract Class E_Devices
E_Devices::E_Devices()
{
    MaSP = "";
    TenSP = "";
    NSX = "";
    TypeTB = Quat;
}

// Phương thức ảo cho hàm nhập (2 loại Thiết bị điện)
void E_Devices::input() {
    cout << "Nhap ma san pham (MaSP): ";
    cin >> MaSP;
    cin.ignore();

    cout << "Nhap ten san pham (TenSP): ";
    getline(cin, TenSP);

    cout << "Nhap noi san xuat (NSX): ";
    getline(cin,NSX);
}

// Hàm Set TypeTB
void E_Devices::setTypeTB(int type) {
    // Gán loại thiết bị điện dựa trên lựa chọn của người dùng
    switch (type) {
        case 1:
            TypeTB = Quat; // Loại thiết bị điện là quạt
            break;
        case 2:
            TypeTB = May_Lanh; // Loại thiết bị điện là máy lạnh
            break;
        case 3:
            TypeTB = May_Lanh; // Loại thiết bị điện là máy lạnh (nếu có thêm loại khác, có thể điều chỉnh ở đây)
            break;
        default:
            cout << "Loai thiet bi dien khong hop le. Mac dinh la Quat." << endl;
            TypeTB = Quat; // Mặc định là quạt nếu nhập không hợp lệ
    }
}

// Hàm Get MaSP
string E_Devices::getMaSP() {
    return MaSP; // Trả về mã sản phẩm
}

// Hàm Get TenSP
string E_Devices::getTenSP() {
    return TenSP; // Trả về tên sản phẩm
}

// Hàm Get NuocSX
string E_Devices::getNuocSX() {
    return NSX; // Trả về nơi sản xuất
}

// Phương thức ảo cho hàm nhập của Class Fan_Devices
void Fan_Devices::input() { 
    // Nhập loại quạt
    int loaiQuat;
    cout << "Nhap loai quat (1: Dung, 2: Hoi Nuoc, 3: Dien): ";
    cin >> loaiQuat;

    if (loaiQuat < 1 || loaiQuat > 3) {
        cout << "Loai quat khong hop le. Mac dinh la Dung." << endl;
        loaiQuat = 1; // Mặc định là quạt đứng nếu nhập không hợp lệ
    }

    else {
        setTypeTB(loaiQuat); // Gán loại thiết bị điện dựa trên lựa chọn của người dùng
    }

    E_Devices::input(); // Gọi hàm nhập từ lớp cha để nhập thông tin chung
}

// Phương thức ảo cho hàm xuất của Class Fan_Devices
void Fan_Devices::output() {
    cout << "Ma san pham (MaSP): " << getMaSP() << endl;
    
    switch(this->TypeFan) {
        case Dung:
            cout << "Loai quat: Quat dung" << endl;
            break;
        case Hoi_Nuoc:
            cout << "Loai quat: Quat hoi nuoc" << endl;
            break;
        case Dien:
            cout << "Loai quat: Quat dien" << endl;
            break;
        default:
            cout << "Loai quat khong xac dinh" << endl;
    }

    cout << "Ten san pham (TenSP): " << getTenSP() << endl;
    cout << "Noi san xuat (NSX): " << getNuocSX() << endl;   
}

// Hàm nhập cho Lớp Quạt Đứng
void Quat_Dung::input() {
    Fan_Devices::input(); // Gọi hàm nhập từ lớp cha để nhập thông tin chung
}

// Hàm lấy Giá Bán cho Lớp Quạt Đứng
double Quat_Dung::getGiaBan() {
    return 500; // Giá bán cố định cho quạt đứng
}

// Hàm xuất cho Lớp Quạt Đứng
void Quat_Dung::output() {
    Fan_Devices::output(); // Gọi hàm xuất từ lớp cha để xuất thông tin chung
    cout << "Gia ban: " << getGiaBan() << " VND" << endl; // Xuất giá bán của quạt đứng
}

// Hàm nhập cho Lớp Quạt Hơi Nước
void Quat_Hoi_Nuoc::input() {
    cout << "Nhap dung tich nuoc toi da (lit): ";
    cin >> Dung_Tich_TD; // Nhập dung tích nước tối đa cho quạt hơi nước
    Fan_Devices::input(); // Gọi hàm nhập từ lớp cha để nhập thông tin chung
}

// Hàm lấy Giá Bán cho Lớp Quạt Hơi Nước
double Quat_Hoi_Nuoc::getGiaBan() {
    return 400 * Dung_Tich_TD; // Giá bán cố định cho quạt hơi nước
}

// Hàm xuất cho Lớp Quạt Hơi Nước
void Quat_Hoi_Nuoc::output() {
    Fan_Devices::output(); // Gọi hàm xuất từ lớp cha để xuất thông tin chung
    cout << "Dung tich nuoc toi da: " << Dung_Tich_TD << " lit" << endl; // Xuất dung tích nước tối đa
    cout << "Gia ban: " << getGiaBan() << " VND" << endl; // Xuất giá bán của quạt hơi nước
}

// Hàm nhập cho Lớp Quạt Điện
void Quat_Dien::input() {
    cout << "Nhap dung luong pin (mAh): ";
    cin >> Dung_Luong_Pin; // Nhập dung lượng pin cho quạt điện
    Fan_Devices::input(); // Gọi hàm nhập từ lớp cha để nhập thông tin chung
}

// Hàm lấy Giá Bán cho Lớp Quạt Điện
double Quat_Dien::getGiaBan() {
    return 500 * Dung_Luong_Pin; // Giá bán cố định cho quạt điện
}

// Hàm xuất cho Lớp Quạt Điện
void Quat_Dien::output() {
    Fan_Devices::output(); // Gọi hàm xuất từ lớp cha để xuất thông tin chung
    cout << "Dung luong pin: " << Dung_Luong_Pin << " mAh" << endl; // Xuất dung lượng pin
    cout << "Gia ban: " << getGiaBan() << " VND" << endl; // Xuất giá bán của quạt điện
}

// Hàm nhập cho Lớp Máy Lạnh
void Air_Conditioner::input() {
    // Nhập loại máy lạnh
    int loaiMayLanh;
    cout << "Nhap loai may lanh (1: Mot chieu, 2: Hai chieu): ";
    cin >> loaiMayLanh;

    if (loaiMayLanh < 1 || loaiMayLanh > 2) {
        cout << "Loai may lanh khong hop le. Mac dinh la Mot chieu." << endl;
        loaiMayLanh = 1; // Mặc định là máy lạnh một chiều nếu nhập không hợp lệ
    }

    else {
        setTypeTB(loaiMayLanh + 2); // Gán loại thiết bị điện dựa trên lựa chọn của người dùng (bắt đầu từ 3)
    }

    E_Devices::input(); // Gọi hàm nhập từ lớp cha để nhập thông tin chung
}

// Hàm xuất cho Lớp Máy Lạnh
void Air_Conditioner::output() {
    cout << "Ma san pham (MaSP): " << getMaSP() << endl;
    
    switch(this->TypeAC) {
        case Mot_Chieu:
            cout << "Loai may lanh: Mot chieu" << endl;
            break;
        case Hai_Chieu:
            cout << "Loai may lanh: Hai chieu" << endl;
            break;
        default:
            cout << "Loai may lanh khong xac dinh" << endl;
    }

    cout << "Ten san pham (TenSP): " << getTenSP() << endl;
    cout << "Noi san xuat (NSX): " << getNuocSX() << endl;   
}