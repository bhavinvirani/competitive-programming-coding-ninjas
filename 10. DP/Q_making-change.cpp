#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coin_change(int amount, int *coins, int numCoins)
{
    if (amount == 0)
        return 1; //* 1 combination find
    if (amount < 0)
        return 0; //* when amount decreases to negative
    if (numCoins == 0)
        return 0; //* whene there are no more coins to choose

    //* include the 0th coin
    int first = coin_change(amount - coins[0], coins, numCoins);
    //* exclude the 0th coin
    int second = coin_change(amount, coins + 1, numCoins - 1);

    return first + second;
}

int coin_change_memo(int amount, int *coins, int numCoins, vector<vector<int>> memo)
{
    if (amount == 0)
        return 1; //* 1 combination find
    if (amount < 0)
        return 0; //* when amount decreases to negative
    if (numCoins == 0)
        return 0; //* whene there are no more coins to choose

    if (memo[amount][numCoins] > -1)
    {
        return memo[amount][numCoins];
    }

    //* include the 0th coin
    int first = coin_change_memo(amount - coins[0], coins, numCoins, memo);
    //* exclude the 0th coin
    int second = coin_change_memo(amount, coins + 1, numCoins - 1, memo);

    memo[amount][numCoins] = first + second;

    return first + second;
}

ll coin_change_iter(ll *coins, int n, int amount)
{
    ll dp[n + 1][amount];

    for (int i = 0; i < amount; i++)
    {
        dp[0][i] = 1;
    }

    int x,y;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < amount; j++)
        {
            // Count of solutions including S[j]
            x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? dp[i][j - 1] : 0;

            // total count
            dp[i][j] = x + y;
        }
    }
    return dp[n][amount - 1];
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
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll amount;
        cin >> amount;

        // int ans = coin_change(amount, arr, n);

        // vector<vector<int>> memo(amount + 1, vector<int>(n+1,-1));
        // int ans = coin_change_memo(amount, arr, n, memo);

        ll ans = coin_change_iter(arr, amount, n);
        cout << ans << endl;
    }
    return 0;
}