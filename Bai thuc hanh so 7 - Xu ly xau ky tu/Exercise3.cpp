#include<bits/stdc++.h>
using namespace std;

/*
Input:
    - Cho xâu ký tự s chỉ chứa các chữ cái, chữ số và dấu cách.
Output:
    - Cho biết xâu ký tự p = “1000” có xuất hiện trong xâu s hay không?
Cài đặt chương trình thực hiện:
    - Cài đặt hàm biểu diễn thuật toán Boyer Moore Horspool tìm và trả về vị trí xuất hiện (đầu tiên) của xâu p trong xâu s.
    - Khởi tạo một xâu ký tự s.
    - Sử dụng thuật toán Boyer Moore Horspool cho biết xâu p = “1000” có xuất hiện trong xâu s hay không? Thông báo kết quả.
    - Thay thế xâu p = “1000” tìm được trong xâu s bằng xâu q = “mot nghin dong”, hiển thị xâu mới
*/

// tim va tra ve vi tri xuat hien dau tien cua xau p trong xau s (neu xau p co trong xau s)
int boyerMooreHorspool(const string& s, const string& p){
    int len_s = s.length();
    int len_p = p.length();

    int i=0;
    while(i++ <= len_s - len_p){
        int j = len_p - 1;
        while(j >= 0 && p[j] == s[i+j]){
            j--;
        }
        if(j < 0) return i;
    }

    return -1;
}


int main(){
    string s;
    cout << "Nhap chuoi s: "; 
    fflush(stdin); getline(cin, s);

    string p = "1000";
    const string replaceStr = "mot nghin dong";

    // kiem tra xau p co xuat hien trong xau s khong
    int pos = boyerMooreHorspool(s, p);
    if(pos != -1){
        cout << "Chuoi \"1000\" xuat hien tai vi tri " << pos << " trong chuoi s" << endl;

        // replace string "1000" into string "mot nghin dong";
        s.replace(pos, p.length(), replaceStr);

        cout << "Chuoi sau khi thay the: " << s << endl;
    }else{
        cout << "Chuoi \"1000\" khong xuat hien trong chuoi s." << endl;
    }
}