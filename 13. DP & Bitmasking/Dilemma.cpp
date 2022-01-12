#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][1 << 12];

int solve(int n, vector<string> v, int mask, int pos)
{
    //* only one set bit
    if ((mask & (mask - 1)) == 0)
    {
        return 0;
    }

    //* position more than length of string
    if (pos >= n)
    {
        return 100000;
    }

    if (dp[pos][mask] != 0)
    {
        return dp[pos][mask];
    }

    int touch = 0, mask1 = 0, mask2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        //* current bit set
        if (mask & (1 << i))
        {
            if (v[i][pos] == '0')
            {
                mask1 |= (1 << i);
            }
            else
            {
                mask2 |= (1 << i);
            }
            touch++;
        }
    }
    int option1 = solve(n, v, mask1, pos + 1) + solve(n, v, mask2, pos + 1) + touch;
    int option2 = solve(n, v, mask, pos + 1);
    int ans = min(option1, option2);

    dp[pos][mask] = ans;
    return ans;
}

ll getTouches(vector<string> v, int n)
{
    int ans = solve(v[0].size(), v, (1 << n) - 1, 0);
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
        int n;
        cin >> n;
        vector<string> v;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }

        cout << getTouches(v, n) << endl;
    }
    return 0;
}
