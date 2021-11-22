#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxof(int a, int b, int c){
    return (a > b) ? ((a > c) ? a : c) : (b > c) ? b : c;
}
int minof(int a, int b, int c){
    return (a < b) ? ((a < c) ? a : c) : (b < c) ? b : c;
}

int maxProductSubarray(int arr[], int n){
    int max_so_far = 0;  
    int max_product_at_i = 1, min_product_at_i = 1;

    //? approch 1
    for(int i = 0; i < n; i++){
        //* fresh sundarray start
        if(arr[i] == 0){
            max_product_at_i = 1;
            min_product_at_i = 1;
            continue;
        }
        int temp = max_product_at_i;
        max_product_at_i = maxof(arr[i], (max_product_at_i * arr[i]), (min_product_at_i * arr[i]));
        min_product_at_i = minof(arr[i], (temp * arr[i]), (min_product_at_i * arr[i]));
        max_so_far = max(max_product_at_i, max_so_far);
        // cout << max_so_far << " ";
    }
    // cout << endl;

    //? approch 2
    // for(int i = 0; i < n; i++){
    //     if(arr[i] > 0){ //* positive
    //         max_product_at_i = max_product_at_i * arr[i]; //* alway be positive
    //         min_product_at_i = min(min_product_at_i * arr[i], 1); //* no more than 1

    //     } else if(arr[i] == 0){  //* anything multiply with zero == zero
    //         max_product_at_i = 1;
    //         min_product_at_i = 1;

    //     } else {  //* negative value
    //         int temp = max_product_at_i;
    //         max_product_at_i = max(min_product_at_i * arr[i], 1);  //* -12 * -5 == 60 //* it would be greater than 0
    //         min_product_at_i = temp * arr[i];       //* 24 * -5 == -120
    //     }
    //     max_so_far = max(max_product_at_i, max_so_far);
    // }

    return max_so_far;
    
}

int main() {
    int arr[] = {-2, -3, 4, 5, 6, 0, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }

    cout << maxProductSubarray(arr, size);

    return 0;
}