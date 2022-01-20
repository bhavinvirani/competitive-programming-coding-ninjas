/* Sachin And Varun Problem
Send Feedback
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.
Input Format:
The first line of input consists of an integer
T denoting the number of test cases.
Each test case consists of only one line containing three space-separated integers a, b and d.
Output Format:
For each test case, print the answer in a separate line.
Constraints:
1 ≤ T ≤ 10 ^ 5

1 ≤ a < b ≤ 10 ^ 9

0 ≤ d ≤ 10 ^ 9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10. So, 0 ways are there. */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
typedef long long ll;

// ll solve1(int a, int b, int d, int sum)
// {
//* false in 2 3 7
//     if (sum > d)
//         return 0;
//     if (a == d || b == d || d == 0)
//         return 1;
//     if (a == d && b == d)
//         return 2;

//     if (sum == d)
//     {
//         return 1;
//     }
//     int count = 0;
//     if (sum + a <= d)
//     {
//         count += solve1(a, b, d, sum + a);
//     }
//     if (sum + b <= d)
//     {
//         count += solve1(b, a, d, sum + b);
//     }

//     return count;
// }

struct Triplet
{
    ll gcd;
    ll x;
    ll y;
};

Triplet extendedEuclid(ll a, ll b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet smallAns = extendedEuclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - ((a / b) * smallAns.y);
    return ans;
}

ll mmInverse(ll a, ll m)
{
    ll x = extendedEuclid(a, m).x;
    return (x % m + m) % m;
}

ll solve(ll a, ll b, ll d)
{
    ll y1 = ((d % a) * mmInverse(b, a)) % a;
    ll firstVal = d / b;
    if (firstVal < y1)
    {
        return 0;
    }

    ll n = (firstVal - y1) / a;
    return n + 1;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    ll t;
    cin >> t;

    while (t--)
    {
        ll a, b, d;
        cin >> a >> b >> d;
        // cout << solve2(a, b, d, 0) << endl;
        ll g = __gcd(a, b);

        //* gcd(a,b) % d != 0 // intigral solution not posi
        if (d % g != 0)
        {
            cout << 0 << endl;
            continue;
        }
        a /= g;
        b /= g;
        d /= g;

        cout << solve(a, b, d) << endl;
    }

    return 0;
}