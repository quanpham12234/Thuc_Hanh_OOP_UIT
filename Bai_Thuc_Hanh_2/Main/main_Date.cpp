#include <iostream>
#include "../Header/Date.h"
using namespace std;

int main() {
    Date date;
    date.Nhap();
    cout << "Ngay ban nhap la: ";
    date.Xuat();

    Date next_date = date.NgayThangNamTiepTheo();
    cout << "Ngay tiep theo: "; 
    next_date.Xuat();
    
    return 0;
}



