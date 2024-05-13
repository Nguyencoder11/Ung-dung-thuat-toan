#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho trước n loại tiền xu có mệnh giá lần lượt là x1, x2, ..., xn và một số tiền m.
- Giả sử rằng mỗi loại mệnh giá tiền xu có số lượng đồng xu là vô hạn.
Output:
- Tính p số lượng đồng xu ít nhất cần lấy để có tổng mệnh giá bằng m.
Thực hiện các yêu cầu sau:
- Thiết kế thuật toán A1 để tính và trả về p số lượng đồng xu ít nhất cần lấy để
có tổng mệnh giá bằng m bằng chiến lược tham lam.
- Cài đặt chương trình:
o Cài đặt hàm F1 biểu diễn thuật toán A1.
o Khởi tạo n, m và {x1, x2, ..., xn}.
o Sử dụng thuật toán A1 để tính và đưa ra p
*/

int minimumCoins(vector<int>& coins, int n, int m, vector<int>& countCoins) {
    int count = 0;
    sort(coins.rbegin(), coins.rend()); // sap xep danh sach menh gia giam dan

    for(int i=0; i<n; i++){
        while(m >= coins[i]) {
            count++;
            m -= coins[i];
            countCoins[i]++;
        }
    }

    return count;
}

int main(){
    int n = 9;  // so loai tien xu
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500}; // menh gia k dong
    vector<int> countCoins(n, 0);   // mang dem so luong dong xu da lay tuong ung vs moi menh gia
    int m;
    cout << "Menh gia tien can lay: ";
    cin >> m;

    int p = minimumCoins(coins, n, m, countCoins);
    cout << "So luong dong xu it nhat can lay de co menh gia bang " << m << " la " << p << endl;

    cout << "Cac menh gia va so luong da lay: " << endl;
    for(int i=0; i<n ; i++){
        if(countCoins[i] > 0) {
            cout << "Menh gia " << coins[i] << ": " << countCoins[i] << endl;
        }
    }

    for(int val : coins) {
        cout << val << " ";
    }
    cout<<endl;
    for(int coin : countCoins){
        cout << coin << " ";
    }
}