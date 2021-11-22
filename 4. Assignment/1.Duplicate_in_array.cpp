#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int duplicate(int arr[], int n){

    //? aproch 1 [O(n^2)]
    //* Bruteforce
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         if(i!=j && arr[i] == arr[j]) return arr[i];
    //     }
    // }
    
    //? aproch 2 [O(n) + O(log n)]
    //* frequency count
    // map<int, int> feq;
    // for(int i = 0; i < n; i++){
    //     feq[arr[i]]++;
    // }
    // for(auto x: feq){
    //     if(x.second > 1) return x.first;
    // }
    
    //? aproch 3  [O(n logn)]
    //* sort and compare
    // sort(arr, arr+n);
    // for (int i = 1; i < n; i++)
    // {
    //     if(arr[i] == arr[i-1]) return arr[i];
    // }

    //? aproch 4 [O(n)]
    //* sum all and minus first N number
    int sum = 0;
     for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ans = sum - (n-2*n-1)/2 ;

    

    
}

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = duplicate(arr, n);

    return 0;
}