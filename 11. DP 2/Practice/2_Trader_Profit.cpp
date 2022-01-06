#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k, int isOnGoing, int dp[][11][2]){
    if(n == 0) return 0;
    // if(n == 1 && isOnGoing == false) return 0;

    if(dp[n][k][isOnGoing] > -1){
        return dp[n][k][isOnGoing];
    }
    // ignore
    int ans = solve(arr + 1, n-1, k, isOnGoing, dp);

    // Buy or sell
    int option;
    if(isOnGoing){
        //* sell
        option = solve(arr + 1, n-1, k-1, 0, dp) + arr[0];
        ans = max(ans, option);
    } else {
        //* Buy  //* only if k > 0
        if(k == 0){
            ans = 0;
        } else {
            option = solve(arr + 1, n-1, k, 1, dp) - arr[0];
            ans = max(ans, option);
        }
    }
    dp[n][k][isOnGoing] = ans;
   
    return ans;

}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        int dp[n+1][11][2];
        memset(dp, -1, sizeof(dp));
        cout << solve(price, n, k, 0, dp) << endl;

    }
    return 0;
}