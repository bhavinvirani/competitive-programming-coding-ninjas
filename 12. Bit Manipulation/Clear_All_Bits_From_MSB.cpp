#include <bits/stdc++.h>
using namespace std;

int solve(int n, int i)
{
    // int a = 1 << i;
    // int b = a - 1;
    return (n & ((1 << i) -1));
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, i;
        cin >> n >> i;
        cout << solve(n, i) << endl;
        
    }
    return 0;
}