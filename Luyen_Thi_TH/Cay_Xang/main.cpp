#include "He_Thong.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numPeople;
    cout << "Nhap so luong nguoi dung: ";
    cin >> numPeople;

    vector<People> peopleList;
    peopleList.reserve(numPeople);

    for (int i = 0; i < numPeople; i++) {
        cout << "\n[ Nhap thong tin nguoi thu " << i + 1 << " ]\n";
        peopleList.emplace_back();
        peopleList.back().input();
    }

    int numStations;
    cout << "\nNhap so luong cay xang hien co: ";
    cin >> numStations;

    double E5Price, A95Price, DOPrice;
    cout << "\n--- Bang Gia Ban Le Hien Tai (VND/lit) ---\n";
    cout << "Gia xang E5: ";
    cin >> E5Price;
    cout << "Gia xang A95: ";
    cin >> A95Price;
    cout << "Gia dau DO: ";
    cin >> DOPrice;

    vector<GasStation> stationList;
    stationList.reserve(numStations);

    for (int i = 0; i < numStations; i++) {
        cout << "\n[ Nhap thong tin cay xang thu " << i + 1 << " ]\n";
        GasStation station;
        station.input(E5, E5Price);
        station.input(A95, A95Price);
        station.input(DO, DOPrice);
        stationList.push_back(station);
    }

    cout << "\n[ KET QUA TINH LOI/LO ]\n";
    for (int i = 0; i < numStations; i++) {
        long long profit = stationList[i].calculateProfit(E5Price, A95Price, DOPrice);
        cout << "Cay xang " << stationList[i].getStationName() << ": ";
        if (profit > 0)
            cout << "LOI " << profit << " VND\n";
        else if (profit < 0)
            cout << "LO " << -profit << " VND\n";
        else
            cout << "HOA VON\n";
    }

    if (numPeople > 0 && numStations > 0) {
        cout << "\n--- TINH CHI PHI BOM DAY XANG ---\n";
        int pIndex, sIndex;
        cout << "Chon nguoi dung so (1 den " << numPeople << "): ";
        cin >> pIndex;
        cout << "Chon cay xang so (1 den " << numStations << "): ";
        cin >> sIndex;

        if (pIndex < 1 || pIndex > numPeople || sIndex < 1 || sIndex > numStations) {
            cout << "Lua chon khong hop le.\n";
            return 0;
        }

        People &selectedPerson = peopleList[pIndex - 1];
        GasStation &selectedStation = stationList[sIndex - 1];

        long long totalCost = 0;
        cout << "\n>> Dang xu ly cho khach hang: " << selectedPerson.getName()
             << " tai tram " << selectedStation.getStationName() << "...\n";

        for (Vehicle *vehicle : selectedPerson.getVehicles()) {
            Loai_Nhien_Lieu fuelType = vehicle->getBestFuel();
            double costPerLiter = 0;
            string tenNhienLieu;

            if (fuelType == E5) {
                costPerLiter = E5Price;
                tenNhienLieu = "E5";
            } else if (fuelType == A95) {
                costPerLiter = A95Price;
                tenNhienLieu = "A95";
            } else {
                costPerLiter = DOPrice;
                tenNhienLieu = "DO";
            }

            double requiredAmount = vehicle->getDungTichBinhXang() - vehicle->getLuongXangHienTai();
            if (requiredAmount > 0) {
                if (selectedStation.hasEnoughFuel(fuelType, requiredAmount)) {
                    long long costForThisVehicle = static_cast<long long>(requiredAmount * costPerLiter);
                    totalCost += costForThisVehicle;
                    cout << " - Can bom " << requiredAmount << " lit " << tenNhienLieu
                         << " | Chi phi: " << costForThisVehicle << " VND\n";
                } else {
                    cout << " - [TU CHOI] Cay xang khong du " << requiredAmount << " lit "
                         << tenNhienLieu << " de bom cho phuong tien nay!\n";
                }
            } else {
                cout << " - Mot phuong tien da day binh, khong can bom them.\n";
            }
        }

        cout << "\n=> TONG CHI PHI CAN TRA: " << totalCost << " VND\n";
    }

    return 0;
}
