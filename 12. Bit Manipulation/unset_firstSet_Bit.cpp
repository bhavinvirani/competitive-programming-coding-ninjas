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
        // int i = 0;
        // while(!(n & (1 << i))){
        //     i++;
        // }
        // cout << (n &= ~(1 << i)) << endl;
        cout << (n & (n-1)) << endl;
    }
    return 0;
}