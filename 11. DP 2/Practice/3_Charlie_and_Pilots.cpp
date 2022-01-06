#include <bits/stdc++.h>
using namespace std;

int solve(int pilot[], int assistnt[], int n, int diff, int **dp)
{
    if (n == 0)
        return 0;
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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }

        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = solve(a, b, n, 0, dp);
        cout << ans << endl;
    }
    return 0;
}