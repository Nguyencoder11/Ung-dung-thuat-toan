#include<bits/stdc++.h>
using namespace std;


/* 
 * Su dung de quy co nho de tim so fibonacci thu n 
 */

long fibonacci(long n, vector<long>& memo){
    if(n<=1){
        return n;
    }else if(memo[n] != -1){
        return memo[n];
    }else{
        memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
        return memo[n];
    }
}

int main(){
    int n;
    cout << "So fibonacci thu n: ";
    cin >> n;

    vector<long> memo(n+1, -1);
    cout << "So fibonacci thu " << n << " la: " <<  fibonacci(n, memo);
}