/* Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length
Line 2 : String V of length
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= |S|, |V| <= 1000
Sample Input :
babab
babba
Sample Output :
3 */

#include <bits/stdc++.h>
using namespace std;

int helper(string s, string v, int n, int m, int **dp)
{
    if (n == 0)
    {
        return 1001;
    }
    if (m == 0)
    {
        return 1;
    }
    int ans;
    //* skip first character of s1 and compare with s2
    int options1 = helper(s.substr(1), v, n - 1, m, dp);

    //* find first character of s1 in s2
    int i = 0;
    for (; i < m; i++)
    {
        if (s[0] == v[i])
        {
            break;
        }
        //* character not found in s2 then it must be 1.
    }
    if (i == m)
    {
        return 1;
    }
    int options2 = 1 + helper(s.substr(1), v.substr(1), n - 1, m - 1, dp);
    ans = min(options1, options2);
    dp[n][m] = ans;
    return ans;
}

int solve(string s1, string s2)
{
    //? aproch 1
    int n = s1.length();
    int m = s2.length();

    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1];
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    return helper(s1, s2, n, m, dp);

    for (int i = 0; i < s1.length() + 1; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;

    //? aproch 2
    // int m = s1.size();
    // int n = s2.size();

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // for (int i = 0; i < n + 1; ++i)
    // {
    //     dp[m][i] = n - i;
    // }

    // for (int i = 0; i < m + 1; ++i)
    // {
    //     dp[i][n] = m - i;
    // }

    // for (int i = m - 1; i >= 0; --i)
    // {
    //     for (int j = n - 1; j >= 0; --j)
    //     {
    //         int k = j;

    //         while (k < s2.size())
    //         {
    //             if (s2[k] == s1[i])
    //             {
    //                 break;
    //             }
    //             k++;
    //         }
    //         if (k == s2.size())
    //         {
    //             dp[i][j] = 1;
    //             // return 1;
    //         }

    //         int c1 = 1 + dp[i + 1][k + 1];
    //         int c2 = dp[i + 1][j];

    //         dp[i][j] = min(c1, c2);
    //     }
    // }
    // for (auto row : dp)
    // {
    //     for (auto i : row)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // return dp[0][0];
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << endl;
    return 0;
}