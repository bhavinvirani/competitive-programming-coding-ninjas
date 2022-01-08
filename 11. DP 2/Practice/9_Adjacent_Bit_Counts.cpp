#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(int n, int k, int start, int dp[][101][2])
{
    //* only 1 element
    if (n == 0)
    {
        //* no need of consecutive bit so atles 1 (even only one element)
        if (k == 0)
        {
            return 1;
        }
        return 0;
    }
    //* 
    if (k < 0)
    {
        return 0;
    }

    if (dp[n][k][start] != -1)
    {
        return dp[n][k][start];
    }

    int ans;
    if (start == 1)
    {
        ans = solve(n - 1, k - 1, 1, dp) + solve(n - 1, k, 0, dp);
    }
    else
    {
        ans = solve(n - 1, k, 1, dp) + solve(n - 1, k, 0, dp);
    }
    dp[n][k][start] = ans;
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
        int n, k;
        cin >> n >> k;
        int dp[101][101][2];
        memset(dp, -1, sizeof(dp));

        cout << solve(n, k, 1, dp) + solve(n, k, 0, dp) << endl;
    }
    return 0;
}