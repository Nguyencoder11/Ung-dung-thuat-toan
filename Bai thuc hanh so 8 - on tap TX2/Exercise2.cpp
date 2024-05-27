#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một số tiền p và một danh sách d gồm n chiếc quạt bàn khác nhau về giá bán, 
thông tin về mỗi chiếc quạt bàn gồm: tên hãng sản xuất, màu sắc, giá bán.
Output:
- Tính u và v lần lượt là số lượng và danh sách ít nhất các quạt bàn trong danh sách d 
cần bán để được một số tiền đúng bằng p.
Yêu cầu thực hiện:
- Thiết kế thuật toán G2 để tính và trả về u và v theo chiến lược tham lam.
- Viết chương trình thực hiện:
o Khai báo cấu trúc dữ liệu của bài toán.
o Khởi tạo p (0 < p < 1200000), n và danh sách d (5 < n < 12). Yêu cầu dữ liệu 
thể hiện được tính thực tiễn.
o Cài đặt hàm F2 biểu diễn thuật toán G2.
o Sử dụng thuật toán G2 để tính và trả về u và v. Hiển thị các kết quả, trong đó 
mỗi chiếc quạt cần hiển thị tên hãng sản xuất và giá bán.
*/

struct Fan{
    string brand;
    string color;
    int price;
};

bool comparePrice(const Fan &a, const Fan &b){
    return a.price > b.price;
}

pair<int, vector<Fan>> greedyAlgorithm(int p, vector<Fan> &fans){
    sort(fans.begin(), fans.end(), comparePrice);

    int total_price = 0;
    vector<Fan> selectedItem;

    for(Fan fan : fans){
        if(total_price + fan.price <= p){
            selectedItem.push_back(fan);
            total_price += fan.price;
            if(total_price == p){
                break;
            }
        }
    }

    if(total_price != p){
        selectedItem.clear();
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
        {"BrandF", "White", 300000},
        {"BrandG", "Pink", 170000},
        {"BrandH", "Orange", 500000},
        {"BrandI", "Purple", 160000},
        {"BrandJ", "Brown", 110000}
    };

    auto result = greedyAlgorithm(p, d);
    int u = result.first;
    vector<Fan> v = result.second;

    cout << "So luong quat ban co the mua: " << u << endl;
    cout << "Danh sach cac quat ban co the mua:" << endl;
    for(Fan fan : v){
        cout << "Brand: " << fan.brand << ", Price: " << fan.price << endl;
    }
}