#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);


    string s;
    cin >> s;
    
    int len = s.length();
    int arr[len];

    for(int i = 0; i < len; i++){
        arr[i] = s[i] - '0';
    }

    int ans[len];
    int lastVal = arr[0];
    ans[0] = arr[0]; //* base case (only one substring)

    //? (last combination sum * 10) + (currntval * it's position)
    /* 
        1               ==> 1           == 1
        2 12            ==> 14 + 1      == 15
        3 23 123        ==> 149 + 15    == 164
        4 34 234 1234   ==>             == 1670
     */
    
    for(int i = 1; i < len; i++){
        int preSum = ans[i-1];
        
        int lastSum = lastVal * 10 + ((arr[i]) * (i + 1));
        lastVal = lastSum;
        ans[i] = lastSum + preSum;
    }

    for(int i = 0; i < len; i++){
        cout << ans[i] << " ";
    }
    return 0;
}