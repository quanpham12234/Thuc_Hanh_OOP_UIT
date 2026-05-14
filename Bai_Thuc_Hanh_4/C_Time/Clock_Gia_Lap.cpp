#include <iostream>
#include <windows.h> // Hỗ trợ hàm gotoxy và Sleep
#include <ctime>     // Hỗ trợ lấy thời gian thực
#include <iomanip>   // Hỗ trợ định dạng in ra (setw, setfill)

using namespace std;

// Hàm di chuyển con trỏ đến tọa độ (x, y) trên màn hình Console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm lấy chiều rộng của cửa sổ Console để canh góc phải
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

class CTime {
private:
    int gio;
    int phut;
    int giay;

public:
    // Constructor mặc định
    CTime(int g = 0, int p = 0, int s = 0) {
        gio = g;
        phut = p;
        giay = s;
    }

    // Phương thức cập nhật thời gian thực từ hệ thống máy tính
    void capNhatThoiGianThuc() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        gio = ltm->tm_hour;
        phut = ltm->tm_min;
        giay = ltm->tm_sec;
    }

    // Phương thức in đồng hồ tại một tọa độ cụ thể
    void inDongHo(int x, int y) {
        // Di chuyển con trỏ tới tọa độ mong muốn
        gotoxy(x, y); 
        
        // In ra với định dạng HH:MM:SS (thêm số 0 ở trước nếu < 10)
        cout << setfill('0') << setw(2) << gio << ":"
             << setfill('0') << setw(2) << phut << ":"
             << setfill('0') << setw(2) << giay;
    }
};

int main() {
    CTime dongHo;
    
    // Tính toán tọa độ X để in ở góc phải
    // Chiều dài chuỗi "HH:MM:SS" là 8 ký tự, ta lùi lại khoảng 10 ký tự cho an toàn
    int width = getConsoleWidth();
    int toaDoX = width - 10; 
    int toaDoY = 0; // Y = 0 là dòng trên cùng của màn hình

    // Xóa toàn bộ màn hình console trước khi chạy
    system("cls");

    // Vòng lặp vô hạn để đồng hồ liên tục chạy
    while (true) {
        // Bước 1: Lấy thời gian mới nhất
        dongHo.capNhatThoiGianThuc();

        // Bước 2: In ra ở góc trên bên phải
        dongHo.inDongHo(toaDoX, toaDoY);

        // Bước 3: Tạm dừng chương trình 1 giây (1000 milliseconds) rồi mới lặp lại
        Sleep(1000); 
    }

    return 0;
}