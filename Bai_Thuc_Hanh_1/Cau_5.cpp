#include <iostream>
#include <string>
using namespace std;

/*
 Cấu trúc: Hoc_sinh
 Tính năng: Lưu trữ thông tin cơ bản và điểm số của một học sinh.
 Thành phần:
 - string ho_ten: Họ và tên học sinh.
 - double toan: Điểm môn Toán.
 - double van: Điểm môn Văn.
 */
struct Hoc_sinh{
    string ho_ten;
    double toan, van;
};

/*
 Hàm: input
 Tính năng: Nhập họ tên, điểm toán và điểm văn cho học sinh từ bàn phím. Xử lý xóa bộ nhớ đệm (cin.ignore) ở cuối hàm để tránh lỗi trôi lệnh khi dùng getline ở các lần gọi sau.
 Đầu vào: 
 - Hoc_sinh &a: Tham chiếu đến biến cấu trúc học sinh cần nhập dữ liệu.
 Đầu ra: Không có (void), nhưng các trường thông tin của 'a' sẽ được gán giá trị người dùng nhập vào.
 */
void input(Hoc_sinh &a)
{
    cout << "Nhap ho ten: ";
    getline(cin,a.ho_ten);

    cout << "Nhap diem toan: ";
    cin >> a.toan;

    cout << "Nhap diem van: ";
    cin >> a.van;

    // Xóa ký tự newline ('\n') còn sót lại
    cin.ignore(); 
}

/*
 Hàm: dtb
 Tính năng: Tính điểm trung bình cộng của môn Toán và môn Văn.
 Đầu vào: 
 - Hoc_sinh a: Biến cấu trúc chứa thông tin điểm của học sinh (truyền tham trị).
 Đầu ra: Trả về kết quả điểm trung bình (kiểu double).
 */
double dtb(Hoc_sinh a)
{
    return (a.van + a.toan)/2;
}

/*
 Hàm: main
 Tính năng: Hàm chính điều khiển luồng thực thi của Bài 5. Khởi tạo một học sinh, gọi hàm nhập dữ liệu và in điểm trung bình ra màn hình.
 Đầu vào: Không có.
 Đầu ra: Trả về 0 báo hiệu chương trình kết thúc thành công.
 */
int main()
{
    Hoc_sinh a;
    input(a);
    cout << "Diem trung binh: " << dtb(a) << endl;
    
    return 0;
}