#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    long prod[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long lp = 1;
    for(int i = 0; i < n; i++){
        prod[i] = lp;
        lp = arr[i] * lp;
    }
    long rp = 1;
    for(int i = n-1; i >= 0; i--){
        prod[i] = prod[i]*rp;
        rp = rp * arr[i];
    } 

    return 0;
}