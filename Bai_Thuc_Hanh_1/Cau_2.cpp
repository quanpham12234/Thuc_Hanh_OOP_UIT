#include <iostream>
#include <cmath>
using namespace std;

/*
 Cấu trúc: ps
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
 Hàm: ucln
 Tính năng: Tìm ước chung lớn nhất (UCLN) của hai số nguyên bằng thuật toán Euclid để hỗ trợ việc rút gọn.
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
 Hàm: rut_gon
 Tính năng: Rút gọn phân số về dạng tối giản bằng cách chia cả tử và mẫu cho UCLN.
 Đầu vào:
 - ps &a: Tham chiếu đến phân số cần rút gọn.
 Đầu ra: Không có (void), nhưng phân số 'a' sẽ thay đổi thành dạng phân số tối giản.
 */
void rut_gon(ps &a)
{
    int uc = ucln(a.tu, a.mau);

    a.tu /= uc;
    a.mau /= uc;
}

/*
 Hàm: chuan_hoa
 Tính năng: Chuẩn hóa phân số sao cho mẫu số luôn dương. Nếu mẫu âm thì đổi dấu cả tử và mẫu.
 Đầu vào:
 - ps &a: Tham chiếu đến phân số cần chuẩn hóa.
 Đầu ra: Không có (void), nhưng phân số 'a' sẽ được cập nhật lại dấu.
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
 Hàm: input
 Tính năng: Nhập dữ liệu tử số và mẫu số cho phân số từ bàn phím. Có vòng lặp ép nhập lại nếu mẫu bằng 0. Tự động chuẩn hóa dấu sau khi nhập hợp lệ.
 Đầu vào:
 - ps &a: Tham chiếu đến cấu trúc phân số cần nhập liệu.
 Đầu ra: Không có (void), nhưng giá trị phân số 'a' sẽ được điền đầy đủ và chuẩn hóa.
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

    chuan_hoa(a);
}

/*
 Hàm: output
 Tính năng: In phân số lớn nhất ra màn hình. Xử lý in số nguyên thay vì phân số nếu tử bằng 0 hoặc mẫu là 1, -1.
 Đầu vào:
 - ps a: Phân số cần in (truyền tham trị).
 Đầu ra: Không có (void), xuất kết quả ra màn hình console.
 */
void output(ps a)
{
    cout << "Phan so lon nhat: ";
    if (a.tu == 0)
        cout << 0;

    else if (a.mau == 1 || a.mau == -1)
        cout << a.tu;

    else
        cout << a.tu << "/" << a.mau;

    cout << endl;
}

/*
 Hàm: ps_lon_nhat
 Tính năng: So sánh hai phân số bằng cách ép kiểu sang số thực (double) để tìm ra phân số có giá trị lớn hơn.
 Đầu vào:
 - ps a: Phân số thứ nhất.
 - ps b: Phân số thứ hai.
 Đầu ra: Trả về phân số (kiểu ps) mang giá trị lớn hơn giữa a và b.
 */
ps ps_lon_nhat(ps a, ps b)
{
    double ps1 = (double)a.tu / a.mau;
    double ps2 = (double)b.tu / b.mau;

    return (ps1 > ps2) ? a : b;
}

/*
 Hàm: main
 Tính năng: Hàm chính điều khiển luồng thực thi. Khởi tạo, nhập hai phân số, gọi hàm tìm phân số lớn nhất, rút gọn nó và in ra màn hình.
 Đầu vào: Không có.
 Đầu ra: Trả về 0 báo hiệu chương trình thực thi thành công không có lỗi.
 */
int main()
{
    ps a, b;
    input(a);
    input(b);
    ps max = ps_lon_nhat(a, b);
    rut_gon(max);
    output(max);
    return 0;
}