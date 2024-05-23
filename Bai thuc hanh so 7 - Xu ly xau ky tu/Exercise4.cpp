#include<bits/stdc++.h>
using namespace std;

/*
Input:
    - Cho một đoạn văn bản s chỉ chứa các chữ cái, chữ số và dấu cách.
Output:
    - Tìm và trả về w là từ đầu tiên của đoạn văn bản s (một từ là một dãy ký tự liên tiếp dài nhất không có chứa dấu cách).
    - Đếm và trả về số lần xuất hiện của từ w trong đoạn văn bản s. 
Cài đặt chương trình thực hiện:
    - Khởi tạo đoạn văn bản s.
    - Cài đặt hàm F1 tìm và trả về từ đầu tiên của của đoạn văn bản s.
    - Cài đặt hàm Z biểu diễn thuật toán z.
    - Sử dụng hàm F1 để tìm và trả về w là từ đầu tiên của s. Hiển thị kết quả.
    - Sử dụng hàm Z để đếm và trả về số lần xuất hiện của w trong s. Hiển thị kết quả.
    - Xóa tất cả các từ w trong đoạn văn bản s. Hiển thị kết quả
*/

// tim tu w dau tien cua chuoi s
string findFirstWordInString(const string& s){
    stringstream ss(s);
    string word;

    ss >> word;

    return word;
}

// dem so luong tu w xuat hien trong chuoi s
int Algorithm_Z(const string& str, const string& word){
    int count = 0;
    string s = word + "$" + str;
    int len_s = s.length();
    vector<int> z(len_s, 0);
    int left = 0, right = 0;

    for(int i=1; i<len_s; i++){
        // truong hop 1: i > right
        if(i > right){
            left = right = i;
            while(right < len_s && s[right - left] == s[right]){
                right++;
            }
            z[i] = right - left; 
            right--;
        }
        // truong hop i < right
        else {
            int k = i - left;
            if(z[k] < right - i + 1){
                z[i] = z[k];
            }else{
                left = i;
                while(right < len_s && s[right - left] == s[right]) {
                    right++;
                }
                z[i] = right - left; 
                right--;
            }
        }
    }

    for(int i=word.length()+1; i<len_s; i++){
        if(z[i] == word.length()){
            count++;
        }
    }

    return count;
}

// xoa tat ca cac tu w co trong chuoi s
string deleteAllWords(const string& s, const string& word){
    string res;
    stringstream ss(s);
    string tmp;

    while(ss >> tmp){
        if(tmp != word){
            res += tmp + " ";
        }
    }

    // remove the trailing space if exists
    if(!res.empty()){
        res.pop_back();
    }

    return res;
}

int main(){
    string s;
    cout << "Nhap chuoi s: ";
    fflush(stdin);
    getline(cin, s);

    string w = findFirstWordInString(s);
    cout << "Tu dau tien trong chuoi s la: " << w << endl;    
    int countWord = Algorithm_Z(s, w);
    cout << "So luong tu '" << w << "' trong chuoi s la " << countWord << endl;
    string newStr = deleteAllWords(s, w);
    cout << "Chuoi sau khi xoa cac tu '" << w << "' la: " << newStr;
}