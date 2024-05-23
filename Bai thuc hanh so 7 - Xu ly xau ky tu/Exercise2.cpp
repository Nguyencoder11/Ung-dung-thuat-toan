#include<bits/stdc++.h>
using namespace std;

/*
Input:
    - Cho một đoạn văn bản tiếng anh p, không quá 50 từ.
Output:
    - Đếm số lượng các từ “child” trong p và thay thế tất cả các từ “child” trong p bằng từ “children”.
Yêu cầu thực hiện
    - Thiết kế thuật toán A3 để đếm và trả về số lượng các từ “child” trong p.
    - Thiết kế thuật toán A4 để thay thế tất cả các từ “child” trong p bằng từ “children”.
    - Cài đặt chương trình ứng dụng:
    - Cài đặt các hàm biểu diễn các thuật toán A3 và A4.
    - Khởi tạo một đoạn văn bản s không quá 50 từ.
    - Sử dụng thuật toán A3 để đếm số từ “child” trong s. Thông báo kết quả.
    - Sử dụng thuật toán A4 để thay thế tất cả các từ child (nếu có) trong p bằng từ “children”. Thông báo kết quả
*/

// count number of words "child" in a string
int countWords(const string& p){
    stringstream ss(p);
    string word;
    int count = 0;

    while(ss >> word){
        if(word == "child"){
            count++;
        }
    }

    return count;
}

// replace all words "child" in p into "children"
string replaceWordsByNewWords(const string& p){
    stringstream ss(p);
    string word;
    vector<string> words;

    while(ss >> word){
        if(word == "child"){
            words.push_back("children");
        }else{
            words.push_back(word);
        }
    }

    string result;
    for(size_t i=0; i<words.size(); i++){
        result += words[i];
        if(i != words.size() - 1){
            result += " ";
        }
    }

    return result;
}

int main(){
    string p = "Every child deserves a chance to learn. A child can make a difference. We must help every child.";

    int count = countWords(p);
    cout << "So luong tu \"child\" trong doan van ban: " << count << endl;

    string modifiedText = replaceWordsByNewWords(p);
    cout << "Doan van ban sau khi thay the: " << modifiedText << endl;
}