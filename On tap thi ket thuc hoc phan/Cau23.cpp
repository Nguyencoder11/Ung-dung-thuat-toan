/*
Cho một số nguyên dương n ≥ 8, một danh sách a gồm n gói hàng, gói hàng thứ
i (1 ≤ i ≤ n) có khối lượng mi và giá trị vi, một số thực C và gia tri P 
Cài đặt chương trình thực hiện:
- Cài đặt thuật toán tham lam để tính D là số lượng gói hàng nhiều nhất có thế lấy 
trong danh sách a để được một giá trị bằng đúng C và cho biết các gói hàng đã lấy
trong a (nếu có). 
- Cài đặt thuật toán qui hoạch động để cho biết cần lấy những gói 
hàng nào trong danh sách a để được giá trị lớn nhất P mà tổng khối lượng không 
vượt quá M.
- Khởi tạo số nguyên dương n, danh sách a với n gói hàng, khởi tạo số C, M. Sử
dụng các thuật toán đã cài đặt ở trên để hiển thị ra màn hình các giá trị D, số thứ tự
gói hàng các gói hàng đã lấy trong a (nếu có phương án). Hiển thị P và giá trị các 
gói hàng đã lấy để được P
*/

#include<bits/stdc++.h>
using namespace std;

struct Bag {
    double m;
    int v;
};

bool compareValue(const Bag &b1, const Bag &b2) {
    return b1.v > b2.v;
}

pair<int, vector<int>> greedyForBag(vector<Bag>& a, double C) {
    sort(a.begin(), a.end(), compareValue);

    double totalValue = 0;
    vector<int> selectedBags;
    for(int i = 0; i < a.size(); i++) {
        if(totalValue + a[i].v <= C) {
            totalValue += a[i].v;
            selectedBags.push_back(i);
        }
    }

    if(totalValue == C) {
        return {selectedBags.size(), selectedBags};
    } else {
        return {0, {}};
    }
}

pair<int, vector<int>> knapsack(vector<Bag>& a, double M) {
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(int(M*100) + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= int(M*100); j++) {
            if(j >= int(a[i -1 ].m * 100)) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - int(a[i-1].m * 100)] + a[i - 1].v);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // truy vet
    double maxValue = dp[n][int(M * 100)];
    vector<int> selectedItems;
    int w = int(M * 100);
    for(int i = n; i > 0 && maxValue > 0; i--) {
        if(maxValue != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            w -= int(a[i - 1].m * 100);
            maxValue -= a[i - 1].v;
        }
    }

    return {dp[n][int(M * 100)], selectedItems};
}

int main(){
    int n = 10;
    vector<Bag> a(n);
    a = {{2.5, 40}, {3.5, 50}, {1.5, 30}, {4.5, 10}, {3.0, 60}, 
         {2.0, 20}, {1.0, 10}, {5.0, 40}, {2.5, 30}, {3.5, 20}};
    double C = 100.0;
    double M = 10.0;    // khoi luong toi da

    // Greedy algorithm
    auto result = greedyForBag(a, C);
    int D = result.first;
    vector<int> items = result.second;

    cout << "So luong nhieu nhat goi hang co the lay : " << D << endl;
    cout << "Danh sach cac goi hang:\n";
    if(!items.empty()) {
        cout << "Danh sach cac goi hang da lay:\n";
        for(int i : items) {
            cout << "Khoi luong: " << a[i].m << ",  gia tri: " << a[i].v << endl;
        }
    } else {
        cout << "Khong co goi hang nao dap ung dieu kien.\n";
    }
    cout << endl;


    // Dynamic programming
    auto dp_result = knapsack(a, M);
    int P = dp_result.first;
    vector<int> dp_items = dp_result.second;

    cout << "Gia tri lon nhat co the lay ma tong khoi luong khong vuot qua M: " << P << endl;
    if(!dp_items.empty()) {
        cout << "Danh sach cac goi hang da lay de duoc P:\n";
        for(int i : dp_items) {
            cout << "Khoi luong: " << a[i].m << ", gia tri: " << a[i].v << endl;
        }
    }
}