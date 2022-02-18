#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd(ll a, ll b)
{
    // special case
    if (a < b)
    {
        return gcd(b, a);
    }
    // base case
    if (b == 0)
    {
        return a;
    }
    // recursive case
    return gcd(b, a % b);
}

ll solve(ll n)
{
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ans += ((n * n) / gcd(i, n));
    }
    ans += 2 * n;
    ans /= 2;
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
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}


