/* Subset Sum - Problem
Send Feedback
Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First-line will contain T(number of test cases), each test case consists of three lines.
First-line contains a single integer N(length of input array).
Second-line contains n space-separated integers denoting the elements of array.
The last line contains a single positive integer k.
Output Format
Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
Constraints:
1 <= T <= 100
1 <= N <= 500
1 <= arr[i] <= 10^4
1 <= K <= 500
Sample Input
1
3
1 2 3
4
Sample Output
Yes */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> num, int n, int s)
{
    vector<vector<int>> dp(2, vector<int>(s + 1, 0));
    for (int i = 0; i < s+1; i++)
    {
        dp[0][i] == false;
    }
    dp[0][0] = true;
    dp[1][0] = true;

    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            //* flag == 0 => 1, flag == 1 => 1
            dp[flag][j] = dp[flag ^ 1][j];

            if (j >= num[i - 1])
            {
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - num[i-1]];
            }
        }
        flag = flag ^ 1;
    }
    return dp[flag^1][s];
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, sum;
        cin >> n;
        vector<int> num;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            num.push_back(x);
        }
        cin >> sum;
        if (check(num, n, sum))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}