#include<bits/stdc++.h>
using namespace std;

// ham dem so luong cac chu cai thuong trong xau s
// su dung chia de tri
int soLuongChuCaiThuong(const string &s, int l, int r) {
    if(l == r) return (s[l] >= 'a' && s[l] <= 'z') ? 1 : 0;
    int m = l + (r-l)/2;
    return soLuongChuCaiThuong(s, l, m) + soLuongChuCaiThuong(s, m+1, r);
}


int main() {
    string s = "Toi la sinh vien Dai hoc Cong nghiep Ha Noi";
    
    int count = soLuongChuCaiThuong(s, 0, s.length()-1);
    if(count != 1) {
        cout << "So luong cac chu cai thuong trong chuoi la: " << count << endl;
        // In ra cac chu cai thuong trong chuoi
        cout << "Cac chu cai thuong la: \n";
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                cout << c << " ";
            }
        }
    }else{
        cout << "Khong co chu cai thuong trong chuoi.";
    }
}