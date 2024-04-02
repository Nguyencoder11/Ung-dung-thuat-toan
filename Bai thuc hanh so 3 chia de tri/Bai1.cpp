#include<bits/stdc++.h>
using namespace std;

// Tao struct luu tru du lieu hoc sinh
struct Student {
    string ten;
    string hoDem;
    int namSinh;
    string diaChi;
};

// Sap xep hoc sinh theo thuat toan quicksort voi do phuc tap O(nlogn)
void quickSort(Student students[], int l, int r) {
    Student pivot = students[l + (r - l) / 2];

    int i = l, j = r;
    while(i < j) {
        while(students[i].ten < pivot.ten) {
            i++;
        }
        while(students[j].ten > pivot.ten) {
            j--;
        }

        if(i <= j) {
            Student tmp = students[i];
            students[i] = students[j];
            students[j] = tmp;
            i++;
            j--;
        }

        if(i < r) {
            quickSort(students, i, r);
        } 
        if(l < j) {
            quickSort(students, l, j);
        }
    }
}

void hienthi(Student students[], int n) {
    cout << setw(15) << "Ho ten" << setw(15) << "Nam sinh" << setw(15) << "Dia chi" << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(15) << students[i].hoDem << " " << students[i].ten << setw(15) << students[i].namSinh << setw(15) << students[i].diaChi << endl;
    } 
}

// tim kiem vi tri cua hoc sinh co ten duoc nhap tu ban phim
int searchStudent(Student students[], const string &name, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        if(students[m].ten == name) return m;
        else if(students[m].ten > name) return searchStudent(students, name, l, m);
        else return searchStudent(students, name, m+1, r);
    }
    return -1;
}

int main(){
    Student students[] = {
        {"Tuan", "Duong Van", 2003, "Bac Giang"},
        {"Tang", "Nguyen Dinh", 2003, "Nghe An"},
        {"Nam", "Nguyen Hai", 2003, "Thai Binh"},
        {"Manh", "Nong Quoc", 2003, "Lang Son"},
        {"Duc", "Pham Minh", 2003, "Quang Ninh"},
        {"Tuan", "Nguyen Ba", 2003, "Ha Noi"}
    };
    int n = sizeof(students)/sizeof(students[0]);
    cout << "DANH SACH SINH VIEN" << endl;

    quickSort(students, 0, n-1);
    hienthi(students, n);


    // Nhap ten sinh vien can tim
    string searchName;
    cout << "Nhap ten sinh vien can tim: ";
    fflush(stdin);
    getline(cin, searchName);

    if(searchStudent(students, searchName, 0, n-1) != -1) {
        for(int i = 0; i < n; i++) {
            if(students[i].ten == searchName) {
                cout << setw(15) << students[i].hoDem << " " << students[i].ten << setw(15) << students[i].namSinh << setw(15) << students[i].diaChi << endl;
            }
        }
    } else {
        cout << "Khong tim thay sinh vien co ten " << searchName << " trong danh sach" << endl;
    }
}