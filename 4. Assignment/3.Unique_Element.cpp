#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int unique(int arr[], int n){

    //? aproch 1 [O(N^2)]
    // for(int i = 0; i < n; i++){
    //     int j = 0;
    //     for(; i < n; j++){
    //         if(i != j && arr[i] == arr[j]){
    //             break;
    //         }
    //     }
    //     if(j == n) {
    //         return arr[i];
    //     }
    // }

    //? aproch 2 [O(N logN)]
    //  if(n==1) return arr[0];
    // sort(arr, arr+n);
 	// for(int i = 0; i < n; i++)   {
    //     if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
    // }

    //? aproch 3 [O(N)]
    int ans = 0;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = unique(arr, n);

    return 0;
}