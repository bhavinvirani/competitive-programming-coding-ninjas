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
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        int i = 0;
        while ((n & (1 << i)) == 0)
        {
            i++;
        }
        cout << (n & (1 << i)) << endl;
    }
    return 0;
}