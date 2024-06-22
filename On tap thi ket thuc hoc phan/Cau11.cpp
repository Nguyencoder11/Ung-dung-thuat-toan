/*
Viết chương trình gồm các yêu cầu sau:
- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số thực.
- Cài đặt một thuật toán tính tổng tất cả các số trong mảng a theo chiến lược chia để
trị. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.
*/

#include <bits/stdc++.h>
using namespace std;

// Hàm chia để trị tính tổng các phần tử trong mảng
double sumOfArray(double a[], int l, int r) {
    // Nếu mảng chỉ có một phần tử, trả về phần tử đó
    if (l == r) {
        return a[l];
    } else {
        // Chia mảng thành hai nửa
        int m = l + (r - l) / 2;
        // Tính tổng bên trái và bên phải
        double leftSum = sumOfArray(a, l, m);
        double rightSum = sumOfArray(a, m + 1, r);
        // Trả về tổng của hai nửa
        return leftSum + rightSum;
    }
}

int main() {
    // Khởi tạo số nguyên dương n >= 10
    int n = 10;
    // Tạo mảng a gồm n số thực
    double a[n] = {1, 2.5, 7.8, -2.6, -9, 0.5, 23, -15, -3.2, 5.8};

    // Tính tổng các phần tử trong mảng sử dụng thuật toán chia để trị
    double sum = sumOfArray(a, 0, n - 1);
    // Hiển thị kết quả lên màn hình
    cout << "Tong cac phan tu trong mang: " << sum << endl;

    return 0;
}
