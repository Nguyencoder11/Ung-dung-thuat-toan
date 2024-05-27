#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho danh sách d gồm n chiếc laptop thuộc các hãng sản xuất khác nhau, thông tin về
mỗi chiếc laptop gồm tên hãng sản xuất, cấu hình, giá bán (ví dụ: HP, CPU 2.5GHz 
upto 3.5GHz-RAM 16GB-SSD 512GB, 15000000; ACER, CPU 2.5GHz upto 
3.5GHz-RAM 8GB-HDD 2TB, 12000000).
Output:
- Tính r là lượng số máy tính trong danh sách d có thông tin bộ nhớ trong là “RAM 
16GB”.
- Tính s và t lần lượt là số lượng và danh sách các máy tính trong danh sách d sử dụng 
ổ cứng loại “SSD”.
Cài đặt chương trình thực hiện:
- Khai báo cấu trúc dữ liệu, khởi tạo n và danh sách d.
- Cài đặt hàm F1 biểu diễn thuật toán Boyer Moore Horspool cho biết vị trí xuất hiện 
đầu tiên của một xâu P trong một xâu T.
- Cài đặt hàm F2 biểu diễn thuật toán Z cho biết một xâu P có xuất hiện trong một xâu 
T hay không?
- Khởi tạo n và danh sách d.
- Cài đặt hàm F3 sử dụng hàm F1 để tính và trả về r.
- Cài đặt hàm F4 sử dụng hàm F2 để tính và trả về s và t.
- Sử dụng hàm F3 để tính và trả về r. Thông báo kết quả.
- Sử dụng hàm F4 để tính và trả về s và t. Thông báo kết quả
*/

struct Laptop {
    string brand;
    string config;
    int price;
};

int BoyerMooreHorspool(const string &p, const string &t){
    int m = p.length();
    int n = t.length();
    if(m > n) return -1;

    int i=0;
    while(i++ <= n-m){
        int j = m - 1;
        while(j>=0 && p[j] == t[i+j]){
            j--;
        }
        if(j < 0) return i;
    }

    return -1;
}


int F3(const vector<Laptop> &laptops){
    int r = 0;
    for(Laptop laptop : laptops){
        if(BoyerMooreHorspool("RAM 16GB", laptop.config) != -1){
            r++;
        }
    }

    return r;
}

bool Algorithm_Z(const string &p, const string &t){
    string s = p + "$" + t;
    int n = s.length();
    vector<int> Z(n, 0);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(i > r){
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            Z[i] = r-l;
            r--;
        }else{
            int k = i - l;
            if(Z[k] < r - i + 1) {
                Z[i] = Z[k];
            }else{
                l = i;
                while(r < n && s[r] == s[r-l]) r++;
                Z[i] = r-l;
                r--;
            }
        }
        if(Z[i] == p.length()){
            return true;
        }
    }
    return false;
}

pair<int, vector<Laptop>> F4(const vector<Laptop> &laptops){
    int s = 0;
    vector<Laptop> t;

    for(Laptop laptop : laptops){
        if(Algorithm_Z("SSD", laptop.config)){
            s++;
            t.push_back(laptop);
        }
    }

    return {s, t};
}

int main(){
    int n = 7;
    vector<Laptop> laptops = {
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
        {"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 12000000},
        {"DELL", "CPU 2.8GHz upto 4.0GHz-RAM 16GB-SSD 1TB", 20000000},
        {"ASUS", "CPU 2.3GHz upto 3.0GHz-RAM 4GB-SSD 256GB", 10000000},
        {"APPLE", "CPU 3.0GHz upto 4.0GHz-RAM 16GB-SSD 512GB", 25000000},
        {"LENOVO", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-SSD 512GB", 14000000},
        {"MSI", "CPU 2.7GHz upto 3.8GHz-RAM 32GB-HDD 1TB", 22000000}
    };

    // Tinh va tra ve r
    int r = F3(laptops);
    cout << "So luong may tinh co thong tin bo nho trong la 'RAM 16GB': " << r << endl;

    // Tinh va tra ve s va t
    auto result = F4(laptops);
    int s = result.first;
    vector<Laptop> t = result.second;
    cout << "So luong may tinh su dung o cung loai 'SSD': " << s << endl;
    cout << "Danh sach cac may tinh su dung o cung loai 'SSD':" << endl;
    for(Laptop laptop : t){
        cout << "Brand: " << laptop.brand << ", Price: " << laptop.price << endl;
    }
}