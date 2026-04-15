#include "Mang.h"
#include <random>
#include <ctime>
#include <algorithm>
#include <climits>

// Kiểm tra 1 số có phải là nguyên tố hay không
bool prime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// Constructor mặc định
cArray::cArray() {} // Vector mặc định là rỗng

// Tạo mảng ngẫu nhiên gồm n số nguyên
cArray::cArray(int n)
{
    if (n <= 0)
    {
        cout << "So luong phan tu phai lon hon 0. Mang se duoc tao voi 0 phan tu.\n";
        return;
    }
    arr.resize(n);

    for (int i = 0; i < n; i++)
        arr[i] = ((rand() % 2 == 0) ? 1 : -1) * (rand() % 100); // Tạo số nguyên ngẫu nhiên trong khoảng [-99, 99]
}

// Xuất mảng
void cArray::Xuat() const
{
    for (int i = 0; i < arr.size(); i++)
        cout << "arr[" << i << "] = " << arr[i] << "\n";
}

// Đếm số lần xuất hiện của giá trị x trong mảng
int cArray::DemSoLanXuatHien(int x) const
{
    int count = 0;
    for (const auto &element : arr)
    {
        if (element == x)
            count++;
    }
    return count;
}

// Kiểm tra các phần tử trong mảng có tăng dần hay không
bool cArray::KiemTraTangDan() const
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false; // Nếu có phần tử nào không tăng thì trả về false
    }
    return true; // Nếu tất cả phần tử đều tăng thì trả về true
}

// Tìm phần lẻ nhỏ nhất trong mảng
int cArray::TimLeNhoNhat() const
{
    int minLe = INT_MAX;
    bool foundLe = false;

    for (const auto &element : arr)
    {
        if (element % 2 != 0) // Kiểm tra nếu là số lẻ
        {
            foundLe = true;
            if (element < minLe)
                minLe = element; // Cập nhật phần lẻ nhỏ nhất
        }
    }

    return foundLe ? minLe : INT_MAX; // Trả về phần lẻ nhỏ nhất hoặc INT_MAX nếu không tìm thấy số lẻ nào
}

// Tìm số nguyên tố lớn nhất trong mảng
int cArray::TimNguyenToLonNhat() const
{
    int maxPrime = INT_MIN;
    bool foundPrime = false;

    for (const auto &element : arr)
    {
        if (prime(element)) // Kiểm tra nếu là số nguyên tố
        {
            foundPrime = true;
            if (element > maxPrime)
                maxPrime = element; // Cập nhật số nguyên tố lớn nhất
        }
    }

    return foundPrime ? maxPrime : INT_MIN; // Trả về số nguyên tố lớn nhất hoặc INT_MIN nếu không tìm thấy số nguyên tố nào
}

// Sắp xếp mảng theo thứ tự tăng dần
void cArray::SapXepTangDan()
{
    sort(arr.begin(), arr.end());
}

// Sắp xếp mảng theo thứ tự giảm dần
void cArray::SapXepGiamDan()
{
    sort(arr.begin(), arr.end(), greater<int>());
}
