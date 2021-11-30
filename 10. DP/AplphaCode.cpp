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

int num_codes_memo(int * arr, int size, int* memo) {

    if(size == 0 || size == 1) return 1;
    
    if(memo[size] > 0){
        return memo[size];
    }

    int output = num_codes_memo(arr, size-1, memo);
    if(arr[size - 2] * 10 + arr[size - 1] <= 26){
        output += num_codes_memo(arr, size-2, memo);
    }

    memo[size] = output;
    return output;
}

int num_codes_i(int* arr, int size){
    int* output = new int[size+1];
    output[0] = 1;
    output[1] = 1;

    for (int i = 2; i <= size; i++)
    {
        //* first combination ()
        output[i] = output[i - 1];

        //* second combination
        //* use when last 3 digits are less than 27
        if(arr[i-2]*10 + arr[i-1] <= 26){
            output[i] += output[i-2];
        }
    }
    int ans = output[size];
    delete [] output;
    return ans;
    
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
    // int memo[n+1] = {0};
    // cout << num_codes_memo(arr, n, memo) << endl;
    // cout << num_codes_i(arr, n) << endl;
    return 0;
}