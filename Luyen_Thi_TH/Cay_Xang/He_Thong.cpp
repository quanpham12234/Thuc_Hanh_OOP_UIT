#include "He_Thong.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Constructor mặc định của Class Engine
Engine::Engine()
{
    A = 0;
    B = 0;
}

// Virtual Destructor của class Engine
Engine::~Engine()
{
}

// Hàm lấy tỷ số nén, phục vụ cho việc lựa chọn loại xăng
double Engine::getTySoNen()
{
    if (B == 0)
        return 0; // Tránh chia cho 0
    return A / B;
}

// Hàm ảo để gợi ý lựa chọn loại xăng
Loai_Nhien_Lieu Engine::typeFuel() {
    double tySoNen = getTySoNen();
    if (tySoNen < 9.5)
        return E5; // Nếu tỷ số nén nhỏ hơn 9.5, gợi ý dùng E5
    else
        return A95; // Nếu tỷ số nén lớn hơn hoặc bằng 9.5, gợi ý dùng A95
}

// Nhập thông tin cho động cơ không có dầu Diesel (DO)
void GasEngine::input() {
    cout << "Nhap the tich buong dot (A): ";
    cin >> A;
    cout << "Nhap the tich xi lanh (B): ";
    cin >> B;
}

// Lựa chọn xăng (E5 hay A95)
Loai_Nhien_Lieu GasEngine::typeFuel() {
    return Engine::typeFuel(); // Sử dụng hàm gợi ý từ lớp cha
}

// Nhập thông tin cho động cơ có dầu Diesel (DO)
void DieselEngine::input() {
    cout << "Nhap the tich buong dot (A): ";
    cin >> A;
    cout << "Nhap the tich xi lanh (B): ";
    cin >> B;
}

// Loại nhiên liệu mặc nhiên là dầu DO
Loai_Nhien_Lieu DieselEngine::typeFuel() {
    return DO; // Động cơ Diesel chỉ sử dụng dầu DO
}

// Virtual Constructor của Abstract Class Vehicle
Vehicle::Vehicle() {
    engine = nullptr; // Khởi tạo con trỏ động cơ là nullptr
    Dung_Tich_Binh_Xang = 0;
    Luong_Xang_Hien_Tai = 0;
}

// Virtual Destructor của Abstract Class Vehicle
Vehicle::~Vehicle() {
    if (engine != nullptr) {
        delete engine; // Giải phóng bộ nhớ động cho động cơ
    }
}

// Hàm Get engine của phương tiện
Engine* Vehicle::getEngine() {
    return engine; // Trả về con trỏ động cơ của phương tiện
}

// Hàm gợi ý loại nhiên liệu tốt nhất cho phương tiện này
Loai_Nhien_Lieu Vehicle::getBestFuel() {
    if (engine != nullptr) {
        return engine->typeFuel(); // Sử dụng hàm typeFuel của động cơ để gợi ý loại nhiên liệu
    }
    return E5; // Nếu không có động cơ, mặc định gợi ý E5
}

// Hàm Get dung tích bình xăng của phương tiện
double Vehicle::getDungTichBinhXang() {
    return Dung_Tich_Binh_Xang; // Trả về dung tích bình xăng của phương tiện
}

// Hàm Get lượng xăng hiện tại của phương tiện
double Vehicle::getLuongXangHienTai() {
    return Luong_Xang_Hien_Tai; // Trả về lượng xăng hiện tại của phương tiện
}

// Hàm nhập thông tin cho loại xe máy
void Motorcycle::input(){
    cout << "Nhap thong tin cho xe may:" << endl;
    engine = new GasEngine(); // Xe máy sử dụng động cơ xăng
    engine->input(); // Nhập thông tin cho động cơ

    cout << "Nhap dung tich binh xang: ";
    cin >> Dung_Tich_Binh_Xang;
    cout << "Nhap luong xang hien tai: ";
    cin >> Luong_Xang_Hien_Tai;
}

// Hàm nhập thông tin cho loại xe ô tô
void Car::input() {
    cout << "Nhap thong tin cho xe o to:" << endl;
    cout << "Lua chon dong co (1: Xang, 2: Diesel): ";
    int fuelChoice;
    cin >> fuelChoice;

    if (fuelChoice == 1) {
        engine = new GasEngine();
    } else {
        engine = new DieselEngine();
    }
    engine->input();

    cout << "Nhap dung tich binh xang: ";
    cin >> Dung_Tich_Binh_Xang;
    cout << "Nhap luong xang hien tai: ";
    cin >> Luong_Xang_Hien_Tai;
}

// Hàm nhập thông tin cho đối tượng thuộc Class People
People::~People() {
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
    vehicles.clear();
}

void People::input() { 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bỏ ký tự newline còn lại trong bộ đệm trước khi nhập tên người
    cout << "Nhap ten nguoi: ";
    getline(cin, name); // Nhập tên người

    cout << "Nhap CCCD: ";
    cin >> CCCD; // Nhập CCCD

    int numVehicles;
    cout << "Nhap so luong phuong tien: ";
    cin >> numVehicles; // Nhập số lượng phương tiện

    // Nhập thông tin cho từng phương tiện
    for (int i = 0; i < numVehicles; i++) {
        int vehicleType;
        cout << "Nhap loai phuong tien (1: Xe may, 2: O to): ";
        cin >> vehicleType; // Nhập loại phương tiện

        Vehicle* vehicle = nullptr;
        if (vehicleType == 1) {
            vehicle = new Motorcycle(); // Tạo đối tượng xe máy
        } else if (vehicleType == 2) {
            vehicle = new Car(); // Tạo đối tượng ô tô
        } else {
            cout << "Loai phuong tien khong hop le. Bo qua." << endl;
            continue; // Nếu loại phương tiện không hợp lệ, bỏ qua
        }

        vehicle->input(); // Nhập thông tin cho phương tiện
        vehicles.push_back(vehicle); // Thêm phương tiện vào danh sách của người
        cout << "\n\n"; // In ra dòng trống để phân tách thông tin giữa các phương tiện
    }
}

// Hàm Get thông tin Name của Class People
string People::getName() {
    return name; // Trả về tên của người
}

// Hàm Get thông tin CCCD của Class People
string People::getCCCD() {
    return CCCD; // Trả về CCCD của người
}

// Hàm Get thông tin các phương tiện mà người này sở hữu
const vector<Vehicle *> &People::getVehicles() const {
    return vehicles; // Trả về danh sách các phương tiện mà người này sở hữu
}

// Constructor mặc định của Class FuelTank
FuelTank::FuelTank() {
    currentFuel = 0; // Khởi tạo lượng xăng hiện tại là 0
    totalCost = 0; // Khởi tạo tổng chi phí là 0
}

// Hàm để nhập thông tin về loại xăng và lượng xăng cần đổ
void FuelTank::input(Loai_Nhien_Lieu fuelType, double CostPerLiter) {
    cout << "Nhap luong xang can do (lit): ";
    cin >> currentFuel; // Nhập lượng xăng cần đổ

    // Tính toán chi phí dựa trên loại xăng
    if (fuelType == E5) {
        totalCost += static_cast<long long>(currentFuel * CostPerLiter); // Giá E5 là 20,000 VND/lít
    } else if (fuelType == A95) {
        totalCost += static_cast<long long>(currentFuel * CostPerLiter); // Giá A95 là 25,000 VND/lít
    } else if (fuelType == DO) {
        totalCost += static_cast<long long>(currentFuel * CostPerLiter); // Giá DO là 15,000 VND/lít
    }
}

// Hàm để lấy lượng xăng hiện tại trong bồn
double FuelTank::getCurrentFuel() {
    return currentFuel; // Trả về lượng xăng hiện tại trong bồn
}

// Hàm để lấy tổng chi phí đã tiêu tốn
long long FuelTank::getTotalCost() {
    return totalCost; // Trả về tổng chi phí đã tiêu tốn
}

// Constructor mặc định của Class GasStation
GasStation::GasStation() {
    stationName.clear();
    numTanks = 3; // Khởi tạo số lượng bồn xăng
}

// Hàm để nhập thông tin về trạm xăng và lượng xăng cần đổ cho khách hàng
void GasStation::input(Loai_Nhien_Lieu fuelType, double CostPerLiter) {
    if (stationName.empty()) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nhap thong tin cho tram xang:" << endl;
        cout << "Ten tram xang: ";
        getline(cin, stationName); // Nhập tên trạm xăng
    }

    // Nhập thông tin cho từng bồn xăng
    if (fuelType == E5) {
        cout << "Nhap thong tin cho bon xang E5:" << endl;
        E5Tank.input(fuelType, CostPerLiter);
    } else if (fuelType == A95) {
        cout << "Nhap thong tin cho bon xang A95:" << endl;
        A95Tank.input(fuelType, CostPerLiter);
    } else if (fuelType == DO) {
        cout << "Nhap thong tin cho bon xang DO:" << endl;
        DOTank.input(fuelType, CostPerLiter);
    }
}

// Hàm để lấy tên trạm xăng
string GasStation::getStationName() {
    return stationName; // Trả về tên trạm xăng
}

// Hàm tính lời/ lỗ dựa trên bảng giá niêm yết
long long GasStation::calculateProfit(double E5Price, double A95Price, double DOPrice) {
    long long profit = 0;

    // Tính lợi nhuận từ bồn xăng E5
    profit += static_cast<long long>(E5Tank.getCurrentFuel() * E5Price) - E5Tank.getTotalCost();

    // Tính lợi nhuận từ bồn xăng A95
    profit += static_cast<long long>(A95Tank.getCurrentFuel() * A95Price) - A95Tank.getTotalCost();

    // Tính lợi nhuận từ bồn xăng DO
    profit += static_cast<long long>(DOTank.getCurrentFuel() * DOPrice) - DOTank.getTotalCost();

    return profit; // Trả về tổng lợi nhuận
}

// Hàm kiem tra xem trạm xăng có đủ nhiên liệu để phục vụ khách hàng hay không
bool GasStation::hasEnoughFuel(Loai_Nhien_Lieu fuelType, double requiredAmount) {
    if (fuelType == E5) {
        return E5Tank.getCurrentFuel() >= requiredAmount; // Kiểm tra bồn xăng E5
    } else if (fuelType == A95) {
        return A95Tank.getCurrentFuel() >= requiredAmount; // Kiểm tra bồn xăng A95
    } else if (fuelType == DO) {
        return DOTank.getCurrentFuel() >= requiredAmount; // Kiểm tra bồn xăng DO
    }
    return false; // Nếu loại nhiên liệu không hợp lệ, trả về false
}