#include <bits/stdc++.h>
using namespace std;

int steps(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return steps(n - 1) + steps(n - 2) + steps(n - 3);
}

int steps_memo(int n, long memo[])
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    if(memo[n] > 0){
        return memo[n];
    }
    
    int output = steps_memo(n-1, memo) + steps_memo(n-2, memo) + steps_memo(n-3, memo);

    memo[n] = output;
    return output;
}

int steps_iter(int n){
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i = 4; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}



int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // int ans = steps(n);
        // long memo[10000000] = {0};
        // int ans = steps_memo(n, memo);
        int ans = steps_iter(n);
        cout << ans << endl;
    }
    return 0;
}