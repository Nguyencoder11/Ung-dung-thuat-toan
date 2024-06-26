#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho danh sách n gói hàng được đánh số thứ tự từ 1 đến n, các gói hàng có 
trọng lượng lần lượt là w1, w2, ..., wn và giá trị lần lượt là v1, v2, ..., vn.
- Cho một chiếc túi có thể chứa được khối lượng tối đa là m.
Output:
- Tính u và d lần lượt là số gói hàng và danh sách các gói hàng cần xếp vào cái 
túi sao cho giá trị lấy được là lớn nhất mà không vượt quá kích thước của cái 
túi.
Yêu cầu thực hiện:
- Thiết kế thuật toán Q2 để tính và trả về u và d bằng chiến lược quy hoạch 
động.
- Cài đặt chương trình ứng dụng:
    o Cài đặt hàm biểu diễn thuật toán Q2.
    o Khởi tạo m, n, {w1, w2, ..., wn}và {v1, v2, ..., vn}.
    o Sử dụng thuật toán Q2 để tính và đưa ra u và d.
*/

pair<int, vector<int>> knapsack(int m, int n, vector<int>& weights, vector<int>& values){
    // khoi tao bang DP
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // xay dung bang DP
    for(int i=1; i<=n; i++){
        for(int w=0; w<=m; w++){
            if(weights[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // truy vet tim danh sach cac goi hang da chon
    int res = dp[n][m];
    int w = m;
    vector<int> selected_item;
    for(int i = n; i>0 && res > 0; i--){
        if(res != dp[i-1][w]){
            selected_item.push_back(i);
            res -= values[i-1];
            w -= weights[i-1];
        }
    }
    reverse(selected_item.begin(), selected_item.end());
    return {selected_item.size(), selected_item};
}

int main(){
    int m = 50;  // kich thuoc toi da cua tui
    int n = 5;  // so luong goi hang
    vector<int> weights = {10, 20, 30, 40, 50};
    vector<int> values = {60, 100, 120, 240, 300};

    auto result = knapsack(m,n,weights,values);
    cout << "So goi hang can xep vao tui: " << result.first << endl;
    cout << "Danh sach cac goi hang can xep vao tui: ";
    for(int item : result.second){
        cout << item << " ";
    }
    cout << endl;
}