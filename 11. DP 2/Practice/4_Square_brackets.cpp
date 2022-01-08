/* Square Brackets
Send Feedback
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]]
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Note: since result can be pretty large output the answer % mod (10^9 + 7).
Input Format:
The first line of the input file contains one integer T(number of test cases), each test case follows as.
The first line contains two integers n and k separated by single space.
The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output Format:
 For each test case print the number of balanced square bracket sequence % mod (10^9 + 7), that can be formed using the above rules in a new line.
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= K <= N
Sample Input
5
1 1
1
1 1
2
2 1
1
3 1
2
4 2
5 7
Sample Output
1
0
2
3
2  */

#include <bits/stdc++.h>
using namespace std;
int  m=pow(10,9)+7;
int solve(int o, int c, int n, bool check[], int **dp)
{
    //* imbalance brackets
    if (o > n || c > n)
        return 0;

    //* no more brackets
    if (o == n && c == n)
        return 1; //* empty string possible

    //* work already done
    if (dp[o][c] != -1)
    {
        return dp[o][c];
    }

    //? three possible cases
    /*
        1. can put only opning bracket //* ki == true, o == c(alredy balanced brackets)
        2. can put only closing bracket //* opning brackets are over
        3. can put both opening and closing bracket //*
     */
    
    int ans;
    if (o == c || check[o + c])
    {
        ans = solve(o + 1, c, n, check, dp)%m;
    }
    else if (o == n)
    {
        ans = solve(o, c + 1, n, check, dp)%m;
    }
    else
    {
        int op1 = solve(o + 1, c, n, check, dp)%m;
        int op2 = solve(o, c + 1, n, check, dp)%m;
        ans = (op1 + op2)%m;
    }
    dp[o][c] = ans;
    return ans;
}
int main()
{
    // freopen("/home/spy/Desktop/input.txt", "r", stdin);
    // freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[k];
        bool check[2 * n] = {false};
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
            check[arr[i] - 1] = true;
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
        cout << solve(0, 0, n, check, dp) << endl;
    }

    return 0;
}