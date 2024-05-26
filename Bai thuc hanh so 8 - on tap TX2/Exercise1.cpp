#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một số tiền p và một danh sách d gồm n chiếc quạt bàn khác nhau về giá bán, 
thông tin về mỗi chiếc quạt bàn gồm: tên hãng sản xuất, màu sắc và giá bán.
Output:
- Tính c và s lần lượt là số lượng và danh sách nhiều nhất các quạt bàn có thể mua được 
từ danh sách d với số tiền p.
Yêu cầu thực hiện: 
- Thiết kế thuật toán G1 để tính và trả về c và s theo chiến lược tham lam.
- Viết chương trình thực hiện:
o Khai báo cấu trúc dữ liệu của bài toán.
o Khởi tạo p (0 < p < 1200000), n và danh sách d (5 < n < 12). Yêu cầu dữ liệu 
thể hiện được tính thực tiễn.
o Cài đặt hàm G1 biểu diễn thuật toán G1.
o Sử dụng thuật toán G1 để tính và trả về c và s. Hiển thị các kết quả, trong đó 
mỗi chiếc quạt cần hiển thị tên hãng sản xuất và giá bán
*/

struct Fan{
    string brand;
    string color;
    int price;
};

bool comparePrice(const Fan &a, const Fan &b){
    return a.price < b.price;
}

// Ham cai dat thuat toan G1
pair<int, vector<Fan>> greedyAlgorithm(int p, vector<Fan> &d){
    sort(d.begin(), d.end(), comparePrice);

    int total_price = 0;    
    vector<Fan> selectedItem;   // mang danh dau cac quat tran duoc chon

    for(Fan fan : d){
        if(total_price + fan.price <= p){
            selectedItem.push_back(fan);
            total_price += fan.price;
        }else{
            break;
        }
    }

    return {selectedItem.size(), selectedItem};
}

int main(){
    int p = 1000000; // Số tiền
    int n = 10; // Số lượng quạt
    vector<Fan> d = {
        {"BrandA", "Red", 100000},
        {"BrandB", "Blue", 150000},
        {"BrandC", "Green", 120000},
        {"BrandD", "Yellow", 90000},
        {"BrandE", "Black", 200000},
        {"BrandF", "White", 130000},
        {"BrandG", "Pink", 170000},
        {"BrandH", "Orange", 80000},
        {"BrandI", "Purple", 160000},
        {"BrandJ", "Brown", 110000}
    };

    auto result = greedyAlgorithm(p, d);
    int c = result.first;
    vector<Fan> s = result.second;

    cout << "So luong qiat ban co the mua: " << c << endl;
    cout << "Danh sach cac quat ban co the mua:" << endl;
    for(Fan fan : s){
        cout << "Brand: " << fan.brand << ", Price: " << fan.price << endl;
    }
}