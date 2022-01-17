#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007



ll solve(string a, string b, string c, int index, int z ,ll dp[][55][55])
{
    //* all charaters checke of c
    if (index >= c.length())
    {
        return 1;
    }

    if (a.length() <= 0 && b.length() <= 0)
    {
        return 0;
    }

    if (dp[a.length()][b.length()][z] != -1)
    {
        return (dp[a.length()][b.length()][z]) % MOD;
    }

    ll ways = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == c[index])
        {
            ways += (solve(a.substr(i + 1), b, c, index + 1, z-1,dp)) % MOD;
            ways %= MOD;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == c[index])
        {
            ways += (solve(a, b.substr(i + 1), c, index + 1, z-1,dp)) % MOD;
            ways %= MOD;
        }
    }
    dp[a.length()][b.length()][z] = (ways %MOD);
    return ways;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        ll dp[55][55][55];
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 55; j++)
            {
                for (int k = 0; k < 55; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << solve(a, b, c, 0, c.length(),dp) << endl;
    }
    return 0;
}
