#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho số tự nhiên n và dãy a gồm n số thực a1, a2, ..., an.
- Một dãy con của dãy a là một cách chọn ra trong dãy a một số phần tử giữ
nguyên thứ tự (dãy a có 2n dãy con như vậy).
Output:
- Tính b là một dãy con của dãy a với b gồm các phần tử có thứ tự tăng với số
phần tử là nhiều nhất (dãy b được gọi là dãy con đơn điệu tăng dài nhất).
Yêu cầu thực hiện:
- Thiết kế thuật toán Q3 để tính và trả về b bằng chiến lược quy hoạch động.
- Cài đặt chương trình ứng dụng:
    o Cài đặt hàm biểu diễn thuật toán Q3.
    o Khởi tạo n và dãy a.
    o Sử dụng thuật toán Q3 để tính và đưa ra b
*/

vector<double> longestIncreasingSubsequence(vector<double> &a){
    int n = a.size();

    if(n==0) return {};

    vector<int> dp(n,1);
    vector<int> prev(n,-1);

    // Tim do dai cua LIS tai moi vi tri
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
    }

    // Tim do dai lon nhat cua LIS va vi tri ket thuc cua no
    int lis_length = 0;
    int lis_end = 0;
    for(int i=0; i<n; i++){
        if(dp[i] > lis_length){
            lis_length = dp[i];
            lis_end = i;
        }
    }

    // Truy vet tim day con tang dai nhat
    vector<double> lis;
    for(int i=lis_end; i>=0; i=prev[i]){
        lis.push_back(a[i]);
        if(prev[i] == -1) break;
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

int main(){
    int n;
    cout << "Nhap so phan tu cua day: "; cin >> n; 
    vector<double> a(n);
    cout << "Nhap cac phan tu cua day a: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<double> b = longestIncreasingSubsequence(a);

    cout << "Day con don dieu tang dai nhat: ";
    for(double value : b){
        cout << value << " ";
    }
    cout << endl;
}