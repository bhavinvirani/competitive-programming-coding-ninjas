#include <bits/stdc++.h>
using namespace std;

int powerExo(int x, int n, int c)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;

    // n = odd
    long ans;
    if (n && 1)
    {
        long smallAns = powerExo(x, n-1, c);
        ans = (x%c);
        ans = (ans*smallAns) % c;
    } else {
        long val = powerExo(x, n/2, c);
        ans =  (val * val) % c;
    }
    return int((ans+c)%c);
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int x, n, c;
    cin >> x >> n >> c;
    cout << powerExo(x, n, c);
    return 0;
}