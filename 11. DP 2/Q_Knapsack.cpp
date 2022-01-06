/* Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack_memo. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13 */
#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight, vector<int> wt, vector<int> v)
{
    //* base case whene there is no remaining weight or No coins
    if (weight < 0 || n == 0)
    {
        return 0;
    }

    //* if current element's w(n-1) is more than remaining weight
    //* can not include into knapsack/bag
    if (wt[n - 1] > weight)
    {
        return knapsack(n - 1, weight, wt, v);
    }

    //* take current coin or not
    return max(v[n - 1] + knapsack(n - 1, weight - wt[n - 1], wt, v), knapsack(n - 1, weight, wt, v));
}

int knapsack_memo(int n, int weight, vector<int> wt, vector<int> v, vector<vector<int>> memo)
{

    if (weight < 0 || n == 0)
    {
        return 0;
    }

    if (memo[n][weight] != -1)
    {
        return memo[n][weight];
    }

    int ans;
    //* if current element's w(n-1) is more than remaining weight
    if (wt[n - 1] > weight)
    {
        ans = knapsack_memo(n - 1, weight, wt, v, memo);
    }
    else
    {
        //* take current coin or not
        ans = max(v[n - 1] + knapsack_memo(n - 1, weight - wt[n - 1], wt, v, memo), knapsack_memo(n - 1, weight, wt, v, memo));
    }

    memo[n][weight] = ans;
    return ans;
}

int knapsack_dp(int n, int weight, vector<int> wt, vector<int> v)
{
    //* N+1 rows and W+1 columns
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));
    /* whene there is no weight or no 0 capacity then answer is 0 */

    //* run for all the values
    for (int i = 1; i <= n; i++)
    {   
        //* run 0 to maximum capacity
        for (int j = 1; j <= weight; j++)
        {   
            //* current weight is less than current capacity ==> then we can include current weight
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            //* exclude current weight
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][weight];
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n, weight;
    vector<int> w;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        w.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> weight;

    // cout << knapsack(n, weight, w, v) << endl;
    // vector<vector<int>> memo(n + 1, vector<int>(weight + 1, -1));
    // cout << knapsack_memo(n, weight, w, v, memo) << endl;

    cout << knapsack_dp(n, weight, w, v) << endl;

    return 0;
}