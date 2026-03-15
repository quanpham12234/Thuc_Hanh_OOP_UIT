#include <iostream>
#include <cmath>
using namespace std;

/*
 Cấu trúc: ps
 Tính năng: Định nghĩa kiểu dữ liệu phân số gồm tử số và mẫu số.
 */
struct ps
{
    int tu, mau;
};

/*
 Hàm: ucln
 Tính năng: Tìm ước chung lớn nhất của hai số nguyên để phục vụ cho việc rút gọn phân số.
 Đầu vào: int a, int b.
 Đầu ra: Trả về UCLN (kiểu int).
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
 Tính năng: Tối giản phân số bằng cách chia tử và mẫu cho ước chung lớn nhất.
 Đầu vào: Tham chiếu đến phân số cần rút gọn (ps &a).
 Đầu ra: Không có (void), phân số truyền vào được tối giản trực tiếp.
 */
void rut_gon(ps &a)
{
    int uc = ucln(a.tu, a.mau);

    a.tu /= uc;
    a.mau /= uc;
}

/*
 Hàm: chuan_hoa
 Tính năng: Đảm bảo mẫu số của phân số luôn mang dấu dương.
 Đầu vào: Tham chiếu đến phân số (ps &a).
 Đầu ra: Không có (void), dấu của tử và mẫu được cập nhật lại nếu mẫu âm.
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
 Tính năng: Yêu cầu người dùng nhập tử và mẫu, bắt lỗi nhập mẫu số = 0 và tự động chuẩn hóa dấu.
 Đầu vào: Tham chiếu đến phân số cần nhập (ps &a).
 Đầu ra: Không có (void).
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
 Tính năng: Xuất phân số ra màn hình, tự động ẩn mẫu số nếu bằng 1 hoặc -1, in 0 nếu tử số bằng 0.
 Đầu vào: Phân số cần xuất (ps a).
 Đầu ra: Không có (void).
 */
void output(ps a)
{
    if (a.tu == 0)
        cout << 0;

    else if (a.mau == 1 || a.mau == -1)
        cout << a.tu;

    else
        cout << a.tu << "/" << a.mau;

    cout << endl;
}

/*
 Hàm: tong
 Tính năng: Tính tổng hai phân số (quy đồng mẫu số), sau đó rút gọn và chuẩn hóa kết quả.
 Đầu vào: Tham chiếu hằng đến hai phân số a và b (const ps& a, const ps& b).
 Đầu ra: Trả về phân số tổng.
 */
ps tong(const ps& a, const ps& b)
{
    ps tong;
    tong.tu = a.tu * b.mau + a.mau * b.tu;
    tong.mau = a.mau * b.mau;

    rut_gon(tong);
    chuan_hoa(tong);

    return tong;
}

/*
 Hàm: hieu
 Tính năng: Tính hiệu hai phân số (quy đồng mẫu số), sau đó rút gọn và chuẩn hóa.
 Đầu vào: Tham chiếu hằng đến hai phân số a và b (const ps& a, const ps& b).
 Đầu ra: Trả về phân số hiệu.
 */
ps hieu(const ps& a, const ps& b)
{
    ps hieu;
    hieu.tu = a.tu * b.mau - a.mau * b.tu;
    hieu.mau = a.mau * b.mau;

    rut_gon(hieu);
    chuan_hoa(hieu);

    return hieu;
}

/*
 Hàm: tich
 Tính năng: Tính tích hai phân số (tử nhân tử, mẫu nhân mẫu), rút gọn và chuẩn hóa.
 Đầu vào: Tham chiếu hằng đến hai phân số a và b (const ps& a, const ps& b).
 Đầu ra: Trả về phân số tích.
 */
ps tich(const ps& a, const ps& b)
{
    ps tich;
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;

    rut_gon(tich);
    chuan_hoa(tich);

    return tich;
}

/*
 Hàm: thuong
 Tính năng: Tính thương hai phân số (nhân nghịch đảo). Có kiểm tra điều kiện phân số chia bị bằng 0.
 Đầu vào: Tham chiếu hằng đến hai phân số a và b (const ps& a, const ps& b).
 Đầu ra: Trả về phân số thương.
 */
ps thuong(const ps& a, const ps& b)
{
    ps thuong;
    
    // Kiểm tra nếu phân số b có giá trị bằng 0 (tử số = 0)
    if (b.tu == 0) {
        cout << "Loi: Khong the chia cho 0! Tra ve phan so 0/1." << endl;
        thuong.tu = 0;
        thuong.mau = 1;
        return thuong;
    }

    thuong.tu = a.tu * b.mau;
    thuong.mau = a.mau * b.tu;

    rut_gon(thuong);
    chuan_hoa(thuong);

    return thuong;
}

/*
 * Hàm: main
 * Tính năng: Điều khiển luồng chương trình, nhập liệu và in kết quả 4 phép tính.
 * Đầu vào: Không có.
 * Đầu ra: Trả về 0 khi kết thúc.
 */
int main()
{
    ps a, b;
    cout << "Nhap phan so a:" << endl;
    input(a);
    cout << "Nhap phan so b: " << endl;
    input(b);

    ps cong, tru, nhan, chia;
    cong = tong(a,b);
    tru = hieu(a,b);
    nhan = tich(a,b);
    chia = thuong(a,b);

    cout << "Phan so a + b = ";
    output(cong);
    cout << "Phan so a - b = ";
    output(tru);
    cout << "Phan so a * b = ";
    output(nhan);
    
    // Chỉ in kết quả chia nếu b không phải là phân số 0
    if (b.tu != 0) {
        cout << "Phan so a / b = ";
        output(chia);
    }
    
    return 0;
}