#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;

    // n = odd
    if (n && 1)
    {
        return x * power(x, n-1);
    } else {
        int val = power(x, n/2);
        return val * val;
    }
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int x, n;
    cin >> x >> n;
    cout << power(x, n);
    return 0;
}