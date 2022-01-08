#include <bits/stdc++.h>
using namespace std;
/* 
    first must be A assistant (age constraint)
 */

//* x = noOfAssists - noOfPilot
int solve(int *assistant, int *captain, int n, int x, int **memo)
{
    //* No Entries
    if (n == 0)
        return 0;

    if (memo[n][x] != -1)
    {
        return memo[n][x];
    }

  
    //* no different between assistant and captain
    if (x == 0)
    {
        int ans = assistant[0]+solve(assistant+1, captain+1, n-1, x+1, memo);
        memo[n][x] = ans;
        return ans;
    }
    else if (x == n)
    {
        //* if x  == remaining unassigned menas all place must be pilots
        //* total 10 (p + assistant) ==> 5 captain selected then next 5 must be an pilots
        int ans = captain[0]+solve(assistant+1, captain+1, n-1, x-1, memo);
        memo[n][x] = ans;
        return ans;
    }
    else
    {
        //* it can be assistant or captain
        int a = assistant[0] + solve(assistant + 1, captain + 1, n - 1, x + 1, memo);
        int b = captain[0] + solve(assistant + 1, captain + 1, n - 1, x - 1, memo);
        int ans = min(a, b);
        memo[n][x] = ans;
        return ans;
    }
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
        int assistant[n], captain[n];
        for (int i = 0; i < n; i++)
        {
            cin >> captain[i] >> assistant[i];
        }

        int **memo = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            memo[i] = new int[(n / 2) + 1];
            for (int j = 0; j <= n / 2; j++)
                memo[i][j] = -1;
        }
        int ans = solve(assistant, captain, n, 0, memo);
        cout << ans << endl;
    }
    return 0;
}