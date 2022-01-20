#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;

int countStrings(string &str)
{
    int n = str.size();
    long long int req = 0, dp[n + 1], arr[n + 1], ans = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = ('Z' - str[i]);
    }
    dp[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        req = (arr[i + 1] + (26ll * req) % MOD) % MOD;
        dp[i] = (arr[i] + (arr[i] * req) % MOD) % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        ans = (ans + dp[i]) % MOD;
    }
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
        string str;
        cin >> str;
        cout << countStrings(str) << endl;
    }
}