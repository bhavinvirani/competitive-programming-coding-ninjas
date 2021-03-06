/* Balika Vadhu- Problem
Send Feedback
Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Format:
First line consists of number of test cases T.
Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Format:
Output consists of T lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.
Constraint:
1 <= T <= 50
1 <= length(b1) , length(b2) <= 100
1 <= K <= 100
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0 */
#include <bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int k, int ***dp)
{
    //* can not make further subsequence (k constraint)
    if (k == 0)
    {
        return 0;
    }
    //* can not make subsequence of k size
    if (k > s1.length() || k > s2.length())
    {
        return 0;
    }
    //* no subsequence can be formed
    if (s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    int n1 = s1.length();
    int n2 = s2.length();

    //* work alredy done
    if (dp[n1][n2][k] != -1)
    {
        return dp[n1][n2][k];
    }

    int ans;
    if (s1[0] == s2[0])
    {
        int ascii = s1[0];
        int option1 = ascii + solve(s1.substr(1), s2.substr(1), k - 1, dp);

        //* if the answer only formd from this character and still we need morethen 1 substring characters then itmust be 0
        if (option1 - ascii == 0 && k > 1)
        {
            option1 = 0;
        }

        int option2 = solve(s1.substr(1), s2, k, dp);
        int option3 = solve(s1, s2.substr(1), k, dp);
        ans = max(option1, max(option2, option3));
    }
    else
    {
        int option1 = solve(s1.substr(1), s2, k, dp);
        int option2 = solve(s1, s2.substr(1), k, dp);
        ans = max(option1, option2);
    }
    dp[n1][n2][k] = ans;
    return ans;
}



int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int k;
        cin >> k;

        int ***dp = new int **[101];
        for (int i = 0; i < 101; i++)
        {
            dp[i] = new int *[101];
            for (int j = 0; j < 101; j++)
            {
                dp[i][j] = new int[101];
                for (int k = 0; k < 101; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        cout << solve(s1, s2, k, dp) << endl;

        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                delete[] dp[i][j];
            }
            delete[] dp[i];
        }
        delete[] dp;
    }

    return 0;
}