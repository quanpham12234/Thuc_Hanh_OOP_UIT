#include <iostream>
#include <cmath>
using namespace std;

/*
 Hàm: ucln
 Tính năng: Tìm ước chung lớn nhất (UCLN) của hai số nguyên bằng thuật toán Euclid.
 Đầu vào: 
 - int a: Số nguyên thứ nhất.
 - int b: Số nguyên thứ hai.
 Đầu ra: Trả về giá trị UCLN (kiểu int) của a và b.
 */
int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (b == 0)
        return a;
    return ucln(b, a % b);
}

/*
 Cấu trúc: ps (Phân số)
 Tính năng: Lưu trữ thông tin của một phân số.
 Thành phần: 
 - int tu: Tử số.
 - int mau: Mẫu số.
 */
struct ps
{
    int tu, mau;
};

/*
 Hàm: input
 Tính năng: Nhập giá trị tử số và mẫu số cho một phân số từ bàn phím. Có vòng lặp kiểm tra để đảm bảo mẫu số phải khác 0.
 Đầu vào: 
 - ps &a: Tham chiếu đến cấu trúc phân số cần nhập liệu.
 Đầu ra: Không có (void), nhưng giá trị của phân số 'a' sẽ được cập nhật sau khi người dùng nhập.
 */
void input(ps &a)
{
    cout << "Nhap tu: ";
    cin >> a.tu;
    do
    {
        cout << "Nhap mau: ";
        cin >> a.mau;
        if (a.mau == 0)
            cout << "Mau khong the bang 0. Hay nhap lai!" << endl;
    } while (a.mau == 0);
}

/*
 Hàm: rut_gon
 Tính năng: Rút gọn phân số bằng cách chia cả tử và mẫu cho UCLN của chúng.
 Đầu vào: 
 - ps &a: Tham chiếu đến phân số cần rút gọn.
 Đầu ra: Không có (void), nhưng giá trị tử và mẫu của phân số 'a' sẽ thay đổi thành dạng phân số tối giản.
 */
void rut_gon(ps &a)
{
    int uc = ucln(a.tu, a.mau);

    a.tu /= uc;
    a.mau /= uc;
}

/*
 Hàm: chuan_hoa
 Tính năng: Chuẩn hóa phân số sao cho mẫu số luôn mang dấu dương (nếu mẫu âm thì đổi dấu cả tử và mẫu).
 Đầu vào: 
 - ps &a: Tham chiếu đến phân số cần chuẩn hóa.
 Đầu ra: Không có (void), nhưng phân số 'a' sẽ được biến đổi để có mẫu số lớn hơn 0 nếu cần.
 */
void chuan_hoa(ps &a)
{
    if (a.mau < 0)
    {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
}

/*
 Hàm: output
 Tính năng: Xuất phân số ra màn hình với các trường hợp đặc biệt (nếu tử = 0 thì in 0, nếu mẫu = 1 hoặc -1 thì chỉ in tử số, ngược lại in dạng tu/mau).
 Đầu vào: 
 - ps a: Phân số cần xuất (truyền tham trị vì hàm này chỉ đọc dữ liệu, không cần thay đổi).
 Đầu ra: Không có (void), in chuỗi ký tự thể hiện phân số ra màn hình console.
 */
void output(ps a)
{
    cout << "Phan so: ";
    if (a.tu == 0)
        cout << 0;

    else if (a.mau == 1 || a.mau == -1)
        cout << a.tu;

    else
        cout << a.tu << "/" << a.mau;

    cout << endl;
}

/*
 Hàm: main
 Tính năng: Hàm chính điều khiển luồng thực thi của Bài 1 (nhập, rút gọn, chuẩn hóa, và xuất phân số).
 Đầu vào: Không có.
 Đầu ra: Trả về 0 (báo hiệu chương trình kết thúc thành công không có lỗi).
 */
int main()
{
    ps a;
    input(a);
    rut_gon(a);
    chuan_hoa(a);
    output(a);
    return 0;
}