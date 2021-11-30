/* Vanya and GCD
Send Feedback
Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?
Input Format:
First line will contain T(number of test case), each test consists of two line.
The first line contains a single integer N denoting size of array A.
The next line contains N space separated integers denoting the elements of array A
Output Format:
Print the required answer Modulo 10^9+7 for each test case in new line
Constraints:
1 <= T <= 50
1 <= N <= 200
1 <= A[i] <= 100
Sample Input
1
3
1 2 3
Sample Output
5 */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int solve(vector<int> vec)
{
    int n = vec.size();

    vector<vector<int>> dp(n, vector<int>(101, 0));
    
    //* whene only one element then GCD is that number itself
    dp[0][vec[0]] = 1;

    //* to fill dp 
    for(int i = 1; i < n; i++){
        //* compare previous GCDs
        //* i-1 to 0
        for (int j = i-1; j >= 0; j--)
        {
            if(vec[i] > vec[j]){ //* when first condition

                for(int k = 1; k < 101; k++){
                    //* take gcd of current number with 1 to 100
                    //* all possible gcd
                    int new_gcd = __gcd(k, vec[i]);

                    //* jth number with curent gcd(k)
                    //* add gcd of dp[j] with the k
                    dp[i][new_gcd] = (dp[i][new_gcd] +  dp[j][k]) % MOD;
                }
            }
        }
        //* atlest 1 gcd for that element
        dp[i][vec[i]]++;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum + dp[i][1]) % MOD;
    }
    return sum;
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
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        cout << solve(vec) << endl;
    }

    return 0;
}