/* Smallest Super-Sequence
Send Feedback
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
First line will contain T(number of test case), each test consists of two lines.
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings for each test case in new line.
Constraints:
1 <= T <= 50
1 <= |str1|, |str2| <= 500
Sample Input:
1
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int l1 = s.length();
        int l2 = t.length();

        int dp[l1+1][l2+1];
        for(int i = 0; i <= l1; i++){
            for (int j = 0; j <= l2; j++)
            {
                if(i == 0){
                    dp[i][j] = j;
 
                } else if(j == 0) {
                    dp[i][j] = i;
                } else if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[l1][l2] << endl;
    }
    return 0;
}