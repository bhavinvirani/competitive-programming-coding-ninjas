/* Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
First line of input will contain T (number of test cases), each test case consists of two lines.
Line 1 : String s
Line 2 : String t
Output Format :
For each test case print the Edit Distance value in new line.
Constraints:
1 <= T <= 100
1<= m,n <= 100
Sample Input 1 :
1
abc
dc
Sample Output 1 :
2
 */
//? find edit distance (How many changes in s1 that s1 became s2);

#include <bits/stdc++.h>
using namespace std;

int solve(char * s1, char * s2, int n1, int n2){
    if(n1 == 0){
        return n2;
    }
    if(n2 == 0){
        return n1;
    }

    if(s1[0] == s2[0]){
        return solve(s1 + 1, s2 + 1, n1 - 1, n2 - 1);
    } else {
        int option1 = solve(s1 + 1, s2 + 1, n1 - 1, n2 - 1) + 1;
        int option2 = solve(s1 + 1, s2, n1 - 1, n2) + 1;
        int option3 = solve(s1, s2 + 1, n1, n2 - 1) + 1;
        return min(option1, min(option2, option3));
    }

}

int solve_iter(char *s1, char *s2){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // for(int i = 1; i <= n1; i++){
    //     dp[i][0] = i;
    // }
    // for(int i = 1; i <= n2; i++){
    //     dp[0][i] = i;
    // }

    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0){
                dp[i][j] = j;
            } else if(j == 0){
                dp[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                //* if current point both the characters are same
                //* same as digonal
                dp[i][j] = dp[i-1][j-1];
            } else {
                //* these are three options can take to make same string different
                //* 1. replce (make same character as s2 then both size decrease)
                //* 2. deletion (decres the length of s1)
                //* 3. insertion (decrease the length of s2 by 1)
                dp[i][j] = 1 +  min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    // for(auto row : dp){
    //     for(auto i : row){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n1][n2];
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        char s1[100];
        char s2[100];
        cin >> s1 >> s2;
        // cout << solve(s1, s2, strlen(s1), strlen(s2)) << endl;
        cout << solve_iter(s1, s2) << endl;
    }

    return 0;
}