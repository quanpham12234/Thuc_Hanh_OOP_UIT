#include <iostream>

using namespace std;

/*
 Hàm: nam_nhuan
 Tính năng: Kiểm tra xem một năm nhập vào có phải là năm nhuận hay không dựa trên quy tắc lịch Gregory.
 Đầu vào: 
 - int nam: Năm cần kiểm tra.
 Đầu ra: Trả về true nếu là năm nhuận, ngược lại trả về false.
 */
bool nam_nhuan(int nam)
{
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
        return true;
    return false;
}

/*
 Hàm: so_ngay_trong_thang
 Tính năng: Xác định số ngày tối đa của một tháng cụ thể trong một năm cụ thể (để xử lý riêng tháng 2 của năm nhuận).
 Đầu vào: 
 - int thang: Tháng cần kiểm tra.
 - int nam: Năm tương ứng của tháng đó.
 Đầu ra: Trả về số ngày (kiểu int) của tháng (28, 29, 30 hoặc 31).
 */
int so_ngay_trong_thang(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default: // Trường hợp tháng 2
        if (nam_nhuan(nam) == true)
            return 29;
        else
            return 28;
    }
}

/*
 Hàm: hop_le
 Tính năng: Kiểm tra bộ ba ngày, tháng, năm người dùng nhập vào có tạo thành một mốc thời gian có thực hay không.
 Đầu vào: 
 - int ngay, int thang, int nam: Bộ dữ liệu thời gian cần kiểm tra.
 Đầu ra: Trả về true nếu ngày tháng năm hợp lệ, false nếu nhập sai (tháng ngoài khoảng 1-12, hoặc ngày vượt quá số ngày của tháng, ngày âm).
 */
bool hop_le(int ngay, int thang, int nam)
{
    if (thang > 12 || thang < 1) return false;

    if (ngay > so_ngay_trong_thang(thang, nam) || ngay < 1) return false; 

    return true;
}

/*
 Hàm: main
 Tính năng: Điều khiển luồng chương trình Bài 4. Yêu cầu nhập ngày tháng năm (có bắt lỗi nhập sai), sau đó tính toán và in ra ngày kế tiếp.
 Đầu vào: Không có.
 Đầu ra: Trả về 0 khi kết thúc chương trình thành công.
 */
int main()
{
    int day, month, year;
    do
    {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;

        if (hop_le(day, month, year) == false)
        {
            cout << "Ngay ban chon khong hop le! Hay nhap lai: " << endl;
        }
    } while (hop_le(day, month, year) == false);

    int next_day = day + 1;
    if (next_day > so_ngay_trong_thang(month, year))
    {
        next_day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    cout << "Ngay ke tiep: " << next_day << "/" << month << "/" << year << endl;

    return 0;
}