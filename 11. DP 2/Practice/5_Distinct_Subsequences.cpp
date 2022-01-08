/* Distinct Subsequences
Send Feedback
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input Format:
First line of input contains an integer T which is equal to the number of test cases.
Each of next T lines contains a string s.
Output Format:
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences. 
Constraints:
T ≤ 100
1 <= length(S) ≤ 10^5
All input strings shall contain only uppercase letters.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int len = s.length();

        int occurrence[256];
        memset(occurrence, -1, sizeof(occurrence));

        //* store subsequence at each index
        ll dp[len + 1];
        dp[0] = 1;


        for(int i = 1; i <= len; i++){
            dp[i] = (dp[i-1] * 2) % MOD;

            //* previously accured this character
            if(occurrence[s[i-1]] != -1){
                dp[i] = (dp[i] - dp[occurrence[s[i-1]]] + MOD) % MOD;
            }
            occurrence[s[i-1]] = i-1;
        }
        cout << dp[len] << endl;
    }
    return 0;
}