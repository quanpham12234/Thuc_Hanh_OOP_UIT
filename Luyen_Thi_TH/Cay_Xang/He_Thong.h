#ifndef HE_THONG_H
#define HE_THONG_H

#include <iostream>
#include <vector>

using namespace std;

enum Loai_Nhien_Lieu
{
    E5,
    A95,
    DO
};
enum Loai_Xe
{
    Xe_May,
    O_To
};

// Class Engine (Động cơ)
class Engine
{
protected:
    double A; // A: Thể tích buồng đốt
    double B; // B: Thể tích xi lanh

public:
    // Constructor mặc định của Class Engine
    Engine();

    // Virtual Destructor của class Engine
    virtual ~Engine();

    // Hàm ảo để nhập thông tin động cơ
    virtual void input() = 0;

    // Hàm lấy tỷ số nén, phục vụ cho việc lựa chọn loại xăng
    double getTySoNen();

    // Hàm ảo để gợi ý lựa chọn loại xăng
    virtual Loai_Nhien_Lieu typeFuel() = 0;
};

class GasEngine : public Engine
{
public:
    // Nhập thông tin cho động cơ không có dầu Diesel (DO)
    void input();

    // Lựa chọn xăng (E5 hay A95)
    Loai_Nhien_Lieu typeFuel();
};

class DieselEngine : public Engine
{
public:
    // Nhập thông tin cho động cơ có dầu Diesel (DO)
    void input();

    // Loại nhiên liệu mặc nhiên là dầu DO
    Loai_Nhien_Lieu typeFuel();
};

// Abstraction Class Vehicle (Phương tiện giao thông)
class Vehicle
{
protected:
    Engine *engine;
    double Dung_Tich_Binh_Xang;
    double Luong_Xang_Hien_Tai;
    Loai_Xe Vehicle_Type;

public:
    // Constructor của Abstract Class Vehicle
    Vehicle();

    // Virtual Input của Abstract Class Vehicle
    virtual void input() = 0;

    // Virtual Destructor của Abstract Class Vehicle
    virtual ~Vehicle();

    // Nhiên liệu tốt nhất cho phương tiện này
    Loai_Nhien_Lieu getBestFuel();

    // Hàm Get engine của phương tiện
    Engine* getEngine();

    // Hàm Get dung tích bình xăng của phương tiện
    double getDungTichBinhXang();

    // Hàm Get lượng xăng hiện tại của phương tiện
    double getLuongXangHienTai();
};

// Class Motorcycle thừa kế Vehicle
class Motorcycle : public Vehicle
{
public:
    // Nhập thông tin cho loại xe máy
    void input();
};

// Class Car thừa kế Vehicle
class Car : public Vehicle
{
public:
    // Nhập thông tin cho loại xe ô tô
    void input();
};

// Class People (Người) sở hữu phương tiện giao thông
class People
{
private:
    string name;
    string CCCD;
    vector<Vehicle *> vehicles;

public:
    // Nhập thông tin cho đối tượng thuộc Class People
    void input();

    // Hàm Get thông tin Name của Class People
    string getName();

    // Hàm Get thông tin CCCD của Class People
    string getCCCD();

    // Hàm Get thông tin các phương tiện mà người này sở hữu
    const vector<Vehicle *> &getVehicles() const;

    // Destructor để giải phóng bộ nhớ cho các phương tiện
    ~People();
};

// Class FuelTank (Bồn xăng) để quản lý lượng xăng trong bồn
class FuelTank
{
private:
    int capacity;        // Sức chứa của bồn xăng
    int currentFuel;     // Lượng xăng hiện tại trong bồn
    long long totalCost; // Tổng chi phí đã tiêu tốn

public:
    FuelTank();

    // Hàm để nhập thông tin về loại xăng và lượng xăng cần đổ
    void input(Loai_Nhien_Lieu fuelType, double CostPerLiter);

    // Hàm để lấy lượng xăng hiện tại trong bồn
    double getCurrentFuel();
    
    // Hàm để lấy tổng chi phí đã tiêu tốn
    long long getTotalCost();
};

// Class GasStation (Trạm xăng) để quản lý các bồn xăng và phục vụ khách hàng
class GasStation {
    private:
    string stationName; // Tên trạm xăng
    int numTanks; // Số lượng bồn xăng tại trạm
    
    FuelTank E5Tank; // Bồn xăng E5
    FuelTank A95Tank; // Bồn xăng A95
    FuelTank DOTank; // Bồn xăng DO

    public:
    GasStation();

    // Hàm để nhập thông tin về trạm xăng và lượng xăng cần đổ cho khách hàng
    void input(Loai_Nhien_Lieu fuelType, double CostPerLiter);

    // Hàm để lấy tên trạm xăng
    string getStationName();

    // Hàm tính lời/ lỗ dựa trên bảng giá niêm yết
    long long calculateProfit(double E5Price, double A95Price, double DOPrice);

    // Hàm để kiểm tra xem trạm xăng có đủ nhiên liệu để phục vụ khách hàng hay không
    bool hasEnoughFuel(Loai_Nhien_Lieu fuelType, double requiredAmount);
};

#endif