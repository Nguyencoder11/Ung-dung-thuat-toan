#include<bits/stdc++.h>
using namespace std;

/*
Input: Cho 2 dãy số a và b có chiều dài lần lượt là n và m chứa các số nguyên.
Output: Tìm c là một dãy con của cả 2 dãy a và b sao cho dãy c có chiều dài lớn nhất.
Yêu cầu thực hiện:
- Thiết kế một thuật toán T tìm và trả về dãy c là dãy con chung của a và b sao cho dãy 
c có chiều dài lớn nhất.
- Viết chương trình thực hiện:
o Khởi tạo n, m, a và b.
o Cài đặt hàm biểu diễn thuật toán T.
o Sử dụng thuật toán T để tìm c. Thông báo kết quả
*/

vector<int> TAlgorithm(const vector<int> &a, const vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Tính giá trị cho bảng dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Truy vết để tìm dãy con chung dài nhất
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    // Đảo ngược dãy kết quả vì truy vết từ cuối lên đầu
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    int n = 5, m = 6;
    vector<int> a = {1,2,3,4,1};
    vector<int> b = {3,4,1,2,1,3};

    vector<int> c = TAlgorithm(a, b);
    cout << "Day con chung dai nhat: ";
    for(int num : c){
        cout << num << " ";
    }
    cout << endl;
}