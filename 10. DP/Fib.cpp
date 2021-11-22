#include <bits/stdc++.h>
using namespace std;

int memo[101] = {0};

int fib1(int n){
    if(n == 0 || n == 1) return 1;

    return fib1(n-1) + fib1(n-2);
}

int fib2(int n){
    if(n == 0 || n == 1) {
        return 1;
    }
    // if(memo[n] > 0){
    //     return memo[n];
    // }
    // memo[n] = fib2( n-1) + fib2(n-2);

    if(memo[n] == 0) {
         memo[n] = fib2( n-1) + fib2(n-2);
    }
    
    return memo[n];
}

int fib3(int n){
    int memo[n];
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}


int main() {

    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    int memo[n] = {0};
    // int ans = fib1(n);
    int ans = fib2(n);
    // int ans = fib3(n);
    cout << ans << endl;
    return 0;
}