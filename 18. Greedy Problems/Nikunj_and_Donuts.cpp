#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool desending(int a, int b)
{
    return (a > b);
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
        ll cal[n];
        for (int i = 0; i < n; i++)
        {
            cin >> cal[i];
        }

        sort(cal, cal + n, desending);

        ll mile = 0;
        // for (auto i : cal)
        // {
        //     cout << i << " ";
        // }

        for (int i = 0; i < n; i++)
        {
            mile = mile + (pow(2,i) * cal[i]);
        }
        cout << mile << endl;
    }
    return 0;
}