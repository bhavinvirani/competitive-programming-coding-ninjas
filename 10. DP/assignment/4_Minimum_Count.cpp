/* Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
First line will contain T(number of test case), each test case consists of a single line containing an integer N.
Output Format :
For each test case print the required minimum count in a newline.
Constraints :
 1 <= T <= 1000
 1 <= N <= 1000
Sample Input 1 :
1
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
1
9
Sample Output 2 :
1 
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if(n == 3 || n == 2 || n == 1 || n == 0){
        return n;
    }

    int ans = INT_MAX;
    //* this loop go till root of n
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solve(n - i*i));
    }
    return ans;

}

int solve_memo(int n, vector<int> memo)
{
    if(n == 3 || n == 2 || n == 1 || n == 0){
        return n;
    }  

    if(memo[n] != -1){
        return memo[n];
    }

    int ans = INT_MAX;
    //* this loop go till root of N
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solve(n - i*i));
    }

    memo[n] = ans;
    return ans;

}

int solve_dp(int n){
    // vector<int> dp(n+1, INT_MAX);
    // dp[0] = 0;
    // dp[1] = 1;
    // dp[2] = 2;
    // dp[3] = 3;

    // for(int i = 1; i*i <= n; i++){
    //     for(int j = 0; i*i+j <= n; j++){
    //         dp[i*i+j] = min(dp[i*i+j], 1 + dp[j]);
    //     }
    // }

    // return dp[n];

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    // to fill all positions
    for(int i = 2; i <= n; i++){
        dp[i] = INT_MAX;  //* initially max value
        
        //* run till 1 to root of i
        for(int j = 1; i-(j*j) >= 0; j++){

            //* current root value is min or not
            dp[i] = min(dp[i], dp[i - (j*j)]);
        }
        
        //* take that element
        dp[i]++;
    }
    return dp[n];

    
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

        // cout << solve(n) << endl;

        // vector<int> memo(n+1, -1);
        // cout << solve_memo(n, memo) << endl;

        cout << solve_dp(n) << endl;
    }
    return 0;
}