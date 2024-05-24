#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho n loại tiền có mệnh giá lần lượt là c1, c2, ..., cn với số lượng tờ tiền mỗi 
loại mệnh giá không giới hạn.
- Cho một số tiền m.
Output:
- Tính s = {s1, s2, ..., sn} là số tờ tiền mỗi loại cần lấy để chi trả vừa đủ số tiền 
m sao cho tổng số lượng tờ tiền phải trả t là ít nhất.
Yêu cầu thực hiện:
- Thiết kế thuật toán Q4 để tính và trả về s và t bằng chiến lược quy hoạch động.
- Cài đặt chương trình ứng dụng:
    o Cài đặt hàm biểu diễn thuật toán Q4.
    o Khởi tạo n và { c1, c2, ..., cn }.
    o Sử dụng thuật toán Q4 để tính và đưa ra s và t
*/

vector<int> minCoinsNeeded(int m, vector<int> &c){
    int n = c.size();
    vector<int> minCoins(m+1, INT_MAX);
    
    minCoins[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = c[i]; j <= m; j++){
            if(minCoins[j-c[i]] != INT_MAX && minCoins[j]>minCoins[j-c[i]]+1){
                minCoins[j] = minCoins[j-c[i]] + 1;
            }
        }
    }

    // truy vet de lay so to tien moi loai
    vector<int> s(n,0);
    int amount = m;
    for(int i = n-1; i>=0; i--){
        while(amount >= c[i] && minCoins[amount]==minCoins[amount - c[i]]+1){
            s[i]++;
            amount -= c[i];
        }
    }

    return s;
}

int main(){
    int n;
    int m;
    cout << "So loai tien: "; cin >> n;
    vector<int> c(n);
    cout << "Gia tri cac loai tien: "; 
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }
    cout << "So tien m: "; cin >> m;

    vector<int> s = minCoinsNeeded(m, c);

    cout << "So to tien moi loai can lay de tra so tien " << m << " la: ";
    for(int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}