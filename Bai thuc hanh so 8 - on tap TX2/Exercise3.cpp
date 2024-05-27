#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một số tiền p và một danh sách d gồm n chiếc quạt bàn khác nhau về giá bán, 
thông tin về mỗi chiếc quạt bàn gồm: tên hãng sản xuất, màu sắc, giá bán.
Output:
- Tính q và t lần lượt là số lượng và danh sách ít nhất các quạt bàn trong danh sách d cần 
bán để được một số tiền lớn p.
Yêu cầu thực hiện:
- Thiết kế thuật toán G3 để tính và trả về q và t theo chiến lược tham lam.
- Viết chương trình thực hiện:
o Khai báo cấu trúc dữ liệu của bài toán.
o Khởi tạo p (0 < p < 1200000), n và danh sách d (5 < n < 12). Yêu cầu dữ liệu 
thể hiện được tính thực tiễn.
o Cài đặt hàm F3 biểu diễn thuật toán G3.
o Sử dụng thuật toán G3 để tính và trả về q và t. Hiển thị các kết quả, trong đó 
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

pair<int, vector<Fan>> greedyAlgorithm(int p, vector<Fan> &d){
    sort(d.begin(), d.end(), comparePrice);

    int total_price = 0;
    vector<Fan> selectedItem;

    for(Fan fan : d){
        selectedItem.push_back(fan);
        total_price += fan.price;
        if(total_price >= p){
            break;
        }
    }

    if(total_price >= p){
        return {selectedItem.size(), selectedItem};
    }else{
        return {0, vector<Fan>()};
    }
}

int main(){
    int p = 750000; // Số tiền
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
    int q = result.first;
    vector<Fan> t = result.second;

    if(q==0){
        cout << "Khong the tim ra tap hop quat de thu duoc so tien >=p" << endl;
    }else{
        cout << "So luong quat can ban: " << q << endl;
        cout << "Danh sach cac quat can ban:" << endl;
        for(Fan fan : t){
            cout << "Brand: " << fan.brand << ", Price: " << fan.price << endl;
        }
    }
}