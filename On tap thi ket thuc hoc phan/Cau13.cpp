/*
Viết chương trình gồm các yêu cầu sau:
- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số thực.
- Cài đặt một thuật toán tính tổng tất cả các số dương trong mảng a theo chiến lược 
chia để trị. Ứng dụng thuật toán và hiển thị kết quả lên màn hình
*/

#include<bits/stdc++.h>
using namespace std;

double sumOfPositiveNumber(const vector<double>& a, int l, int r){
    if(l == r) return (a[l] > 0) ? a[l] : 0;

    int m = l + (r - l) / 2;
    double leftSum = sumOfPositiveNumber(a, l, m);
    double rightSum = sumOfPositiveNumber(a, m + 1, r);

    return leftSum + rightSum;
}

int main(){
    int n = 10;
    vector<double> a(n);
    a = {1, 2.5, 7.8, -2.6, -9, 0.5, 23, -15, -3.2, 5.8};

    double sumOfNumber = sumOfPositiveNumber(a, 0, n-1);
    cout << "Tong cac so duong trong mang: " << sumOfNumber << endl;
}