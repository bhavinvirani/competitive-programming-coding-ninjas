/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format :
The first line of input contains a single integer N denoting the total number of houses.

The second line of input contains N single space-separated integers, denoting the amount of money in every i-th house.
Output Format :
The only line of output will print the maximum amount of loot that is possible.
Input Constraints
0 <= N <= 10^5
0 <= A[i] <= 10^4

Where N is the total number of houses.
A[i] represents the money present in the i-th house.

Time limit: 1sec
Sample Input 1:
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2:
4
10 2 3 11
Sample Output 2 :
21
Explanation to Sample Input 2:
Since the thief cant loot two consecutive houses, the ways in which he may loot are:

1. [10, 3]: a total loot of 13
2. [10, 11]: a total loot of 21
3. [2, 11]: a total loot of 13
4. [10]: a total loot of 10
5. [2]: a total loot of 2
6. [3]: a total loot of 3
7. [11]: a total loot of 11

We can't neglect the option to loot just either of the houses if it yields the maximum loot.

From all the possible seven ways, the second option yields the maximum loot amount and hence the answer.
 */

#include <bits/stdc++.h>
using namespace std;

int max_loot_dp(vector<int> house, int n)
{   
    //* only one house
    if(n == 1){
        return house[0];
    }

    //* only two house
    if(n == 2){
        return max(house[0], house[1]);
    }

    int dp[n];
    dp[0] = house[0];
    dp[1] = max(house[0], house[1]);

    //* either take current position or not
    /* if take current position then (current position) + (i-2)*/
    /* else (i-1) position */

    for(int i = 2; i < n; i++){
        dp[i] = max(house[i] + dp[i - 2], dp[i - 1]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    return dp[n-1];
}

int max_loot_memo(vector<int> house, int i, int n, vector<int> memo)
{
    if(i >= n){
        return 0;
    }
    if(memo[i] != -1){
        return memo[i];
    }

    int smallAns = max(house[i] + max_loot_memo(house, i + 2, n, memo), max_loot_memo(house, i + 1, n, memo));
    memo[i] = smallAns;
    return smallAns;
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
        vector<int> house;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            house.push_back(temp);
        }
        // cout << max_loot(house, 0, n) << endl;

        // vector<int> memo(n, -1);
        // cout << max_loot_memo(house, 0, n, memo) << endl;

        cout << max_loot_dp(house, n) << endl;
    }

    return 0;
}