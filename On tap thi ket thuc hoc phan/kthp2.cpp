#include <bits/stdc++.h>
using namespace std;

struct Coc {
    string label;
    int size;
    int price;
};

// Thuc hien thuat toan tham lam dua ra cac coc voi gia tien lon nhat p ma khong vuot qua m
pair<int, vector<Coc>> greedyAlgorithm(const vector<Coc>& d, int m, int &p) {
    p = 0;
    vector<Coc> lists;

    for (int i = 0; i < d.size(); i++) {
        if (p + d[i].price <= m) {
            lists.push_back(d[i]);
            p += d[i].price;
        } else {
            break;
        }
    }

    return {lists.size(), lists};
}

// Thuc hien quy hoach dong tra ve so luong va danh sach cac coc lay tu danh sach d
// sao cho tong gia tien lon nhat va tong kich thuoc cac coc khong vuot qua s
pair<int, vector<Coc>> dynamicProgramming(const vector<Coc>& d, int s, int &t) {
    int n = d.size();
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));

    // Fill dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (d[i - 1].size <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d[i - 1].size] + d[i - 1].price);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum price achievable without exceeding size s
    t = dp[n][s];
    int w = s;
    vector<Coc> chosenCups;

    // Track back to find the cups selected
    for (int i = n; i > 0 && t > 0; i--) {
        if (t != dp[i - 1][w]) {
            chosenCups.push_back(d[i - 1]);
            w -= d[i - 1].size;
            t -= d[i - 1].price;
        }
    }

    // Correct the value of t to be the total price
    t = dp[n][s];
    return {chosenCups.size(), chosenCups};
}

int main() {
    int n = 6;
    vector<Coc> d = {
        {"Nhan 6", 2, 10000},
        {"Nhan 2", 5, 15000},
        {"Nhan 4", 1, 20000},
        {"Nhan 3", 3, 30000},
        {"Nhan 1", 7, 35000},
        {"Nhan 5", 9, 50000},
    };

    int m = 47000, s = 12;
    int p = 0;

    auto result1 = greedyAlgorithm(d, m, p);
    int u = result1.first;
    vector<Coc> selectedGlasses = result1.second;

    if (u != 0) {
        cout << "Gia lon nhat co the ban ma khong vuot qua " << m << " la: " << p << endl;
        cout << "So luong coc ban nhieu nhat la: " << u << endl;
        cout << "Danh sach cac coc da ban: " << endl;
        for (Coc c : selectedGlasses) {
            cout << "Nhan hieu: " << c.label << ", kich thuoc: " << c.size << endl;
        }
    } else {
        cout << "Khong co phuong an nao." << endl;
    }

    int q;  // So luong coc lay tu danh sach d
    int t;  // Gia tien lon nhat sao cho tong kich thuoc cac coc trong khay h khong vuot qua s

    auto result2 = dynamicProgramming(d, s, t);
    q = result2.first;
    vector<Coc> dpSelectedCups = result2.second;

    if (q != 0) {
        cout << "Gia tien lon nhat sao cho tong kich thuoc cac coc khong vuot qua " << s << " la: " << t << endl;
        cout << "So luong coc duoc chon la: " << q << endl;
        cout << "Danh sach cac coc da chon: " << endl;
        for (Coc c : dpSelectedCups) {
            cout << "Nhan hieu: " << c.label << ", kich thuoc: " << c.size << endl;
        }
    } else {
        cout << "Khong co phuong an nao." << endl;
    }

    return 0;
}
