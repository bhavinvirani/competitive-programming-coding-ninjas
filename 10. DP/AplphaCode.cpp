#include <bits/stdc++.h>
using namespace std;

int num_codes(int * arr, int size) {
    if(size == 0 || size == 1) return 1;

    int output = num_codes(arr, size-1);
    if(arr[size - 2] * 10 + arr[size - 1] <= 26){
        output += num_codes(arr, size-2);
    }
    return output;
}

int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << num_codes(arr, n) << endl;
    return 0;
}