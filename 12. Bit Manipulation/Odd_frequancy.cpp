#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;
    
    while(t--)
    {
       int n;
       cin >> n;
       int arr[n];
       for(int i = 0; i < n; i++){
           cin >> arr[i];
       }
       cout << find(arr, n) << endl;
    }

    return 0;
}