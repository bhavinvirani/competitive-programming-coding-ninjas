/* Coin Change Problem
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
W can be pretty large so output the answer % mod(10^9 + 7)
Input Format
First line will contain T (number of test case), each test case is consists of 3 three lines.
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
For each test case print the number of ways (W) % mod(10^9 +7) in new line.
Constraints :
1 <= T <= 10
1 <= N <= 10
1 <= V <= 5000 */
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