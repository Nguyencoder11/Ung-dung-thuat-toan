#include<bits/stdc++.h>
using namespace std;

/*
Input:
    - Cho xâu ký tự s.
    - Xâu s là đối xứng nếu đọc từ trái qua phải hoặc từ phải qua trái đều giống nhau (ví dụ: memoomem).
Output:
    - Xác định xâu s có phải là xâu đối xứng hay không?
    - Tìm xâu con đối xứng dài nhất trong xâu s có tâm là s[k], với k ≥ 1.
Yêu cầu thực hiện
    - Thiết kế thuật toán A1 để kiểm tra xâu ký tự s có phải là xâu đối xứng hay không?
    - Thiết kế thuật toán A2 để tìm xâu con đối xứng dài nhất trong xâu s có tâm là s[k].
    - Viết chương trình thực hiện:
    o Cài đặt hàm F1 và F2 biểu diễn các thuật toán A1 và A2.
    o Khởi tạo xâu ký tự s.
    o Sử dụng thuật toán A1 để xác định xâu s có phải là một xâu đối xứng hay không? Thông báo kết quả.
    o Nếu s không phải là xâu đối xứng, hãy nhập vào số nguyên k, tìm xâu con đối xứng dài nhất có tâm là s[k], hiển thị kết quả
*/

// check for palindrome string
bool isPalindrome(const string& s){
    int len = s.length();
    for(int i=0; i<len/2; ++i){
        if(s[i] != s[len-i-1]){
            return false;
        }
    }
    return true;
}

// find and return palindrome substring has length is longest
string longestPalindromeSubstring(const string& s, int k){
    int len = s.length();
    int left = k, right = k;

    // mo rong tam k
    while(left>=0 && right<len && s[left] == s[right]){
        left--;
        right++;
    }
    string oddPalindrome = s.substr(left+1, right-left-1);

    // truong hop co tam o giua 2 ky tu s[k] va s[k+1]
    left = k;
    right = k+1;
    while(left>=0 && right<len && s[left] == s[right]){
        left--;
        right++;
    }
    string evenPalindrome = s.substr(left+1, right-left-1);

    return oddPalindrome.length() > evenPalindrome.length() ? oddPalindrome : evenPalindrome;
}

int main(){
    string s;
    cout << "Nhap xau ky tu s: ";
    fflush(stdin);
    getline(cin, s);

    // kiem tra doi xung
    if(isPalindrome(s)){
        cout << "Xau s la xau doi xung" << endl;
    }else{
        cout << "Xau s khong phai la xau doi xung" << endl;
        int k;
        cout << "Nhap tam k: ";
        cin>>k;
        if(k>=0 && k<s.length()){
            string longestString = longestPalindromeSubstring(s, k);
            cout << "Xau con doi xung dai nhat co tam la s[" << k << "] la " << longestString << endl;
        }else{
            cout << "Gia tri k khong hop le.";
        }
    }
}