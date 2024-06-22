/*
Viết chương trình gồm các yêu cầu sau:
- Khởi tạo một số nguyên dương n ≥ 10 và 1 mảng a gồm n số nguyên.
- Cài đặt một thuật toán tính tổng tất cả các số lẻ trong mảng a theo chiến lược đệ
qui. Ứng dụng thuật toán và hiển thị kết quả lên màn hình.
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfOddNumber(const vector<int>& a, const int &index){
    if(index < 0) return 0;
    
    int current = (a[index] % 2 != 0) ? a[index] : 0;
    return current + sumOfArr(a, index - 1);
}

int main(){
    int n = 10;
    vector<int> arr(n);
    arr = {1, 2, -5, 6, -9, 8, 10, -24, -5, 50};

    int sum = sumOfOddNumber(arr, n - 1);
    cout << "Tong cac so le trong mang: " << sum << endl;
}