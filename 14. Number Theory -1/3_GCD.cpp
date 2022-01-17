#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    //* to make a > b
    if (a < b)
    {
        return gcd(b, a);
    }
    
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}