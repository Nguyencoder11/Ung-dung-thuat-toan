#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một chiếc túi có kích thước s và một danh sách d gồm n chiếc điện thoại khác 
nhau, thông tin về mỗi điện thoại gồm nhãn hiệu, kích thước và giá bán.
Output:
- Tính x và a lần lượt là số lượng và danh sách những chiếc điện thoại trong danh sách 
d cần đưa vào chiếc túi để để được tổng giá bán lớn nhất mà không vượt quá kích thước 
s của chiếc túi.
Yêu cầu thực hiện
- Thiết kế thuật toán Q1 để tính và trả về x và a.
- Viết chương trình thực hiện:
- Khởi tạo n và danh sách d (5 ≤ n ≤ 10).
- Cài đặt hàm biểu diễn thuật toán Q1.
- Sử dụng thuật toán Q1 để tính và trả về x và a. Hiển thị kết quả (mỗi điện thoại hiển 
thị nhãn hiệu, giá bán)
*/

struct Phone{
    string brand;
    int size;
    int price;
};

// ham thuc hien thuat toan Q1
pair<int, vector<Phone>> knapsack(int s, vector<Phone> &phones){
    int n = phones.size();
    // tao bang phuong an
    vector<vector<int>> dp(n+1, vector<int>(s+1, 0));

    // xay dung bang phuong an
    for(int i=1; i<=n; i++){
        for(int j=0; j<=s; j++){
            if(phones[i-1].size <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-phones[i-1].size] + phones[i-1].price);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // tim cac dien thoai can chon
    int max_value = dp[n][s];
    int w = s;
    vector<Phone> selectedItems;
    for(int i=n; i>0 && max_value > 0; i--){
        if(max_value != dp[i-1][w]){
            selectedItems.push_back(phones[i-1]);
            max_value -= phones[i-1].price;
            w -= phones[i-1].size;
        }
    }

    return {selectedItems.size(), selectedItems};
}

int main(){
    int s = 15;  // kich thuoc s
    int n = 7;
    vector<Phone> d = {
        {"BrandA", 3, 100},
        {"BrandB", 5, 300},
        {"BrandC", 4, 250},
        {"BrandD", 2, 150},
        {"BrandE", 6, 400},
        {"BrandF", 1, 200},
        {"BrandG", 3, 350}
    };

    auto result = knapsack(s, d);
    int x = result.first;
    vector<Phone> a = result.second;

    cout << "So luong dien thoai co the dua vao tui: " << x << endl;
    cout << "Danh sach cac dien thoai can dua vao tui" << endl;

    for(Phone phone : a){
        cout << "Brand: " << phone.brand << ", Price: " << phone.price << endl;
    }
}