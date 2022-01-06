/* Mehta and Bank Robbery - Problem
Send Feedback
One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken into several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
Input Format:
The first line of input will contain T(number of test cases), each test will follow as.
First Line will contain two integers N and W (number of items and maximum weight respectively).
Second-line will contain N space-separated integers denoting the profit associated with the Ith item.
The third line will contain N space-separated integers denoting the weight of the Ith item.
Output Format:
Output the maximum profit obtainable for each test case in a new line.
Constraints:
1 <= T <= 20
1 <= N, W <= 500
1 <= profit[i] <= 10^4
1 <= weight[i] <= 10^4
Sample Input:
1
7 37
33 5 14 14 16 25 15
5 19 30 4 15 31 25
Sample output:
1591 

3
6 41
9 17 36 22 8 10 
23 14 39 7 30 18 
8 41
40 39 41 30 40 26 10 6 
3 23 13 7 12 39 9 23 
7 41
15 41 10 4 30 30 17 
12 14 10 35 40 1 21 

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, w;
        cin >> n >> w;
        pair<ll, ll> *arr = new pair<ll, ll>[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }
        sort(arr, arr + n);

        ll ***dp = new ll **[2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new ll *[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = new ll[w + 1];
                for (int k = 0; k <= w; k++)
                {
                    dp[i][j][k] = 0;
                }
            }
        }

        int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        //? Base Case
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[0][i][j] = dp[0][i - 1][j];

                if (j >= arr[i - 1].second)
                {
                    dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - arr[i - 1].second] + arr[i - 1].first);
                }
            }
        }

        for (int prime = 1; prime <= 10; prime++)
        {
            int p = prime % 2;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= w; j++)
                {
                    dp[p][i][j] = dp[p][i - 1][j];
                    if (j >= arr[i - 1].second)
                    {
                        dp[p][i][j] = max(dp[p][i][j], max(dp[p][i - 1][j - arr[i - 1].second] + arr[i - 1].first, dp[p ^ 1][i - 1][j - arr[i - 1].second] + arr[i - 1].first * primes[prime]));
                    }
                }
            }
        }
        cout << dp[0][n][w] << endl;
    }
    return 0;
}