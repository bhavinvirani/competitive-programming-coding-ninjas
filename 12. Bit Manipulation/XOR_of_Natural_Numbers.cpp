#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;
    
    while(t--)
    {
       int n;
       cin >> n;
       int ans = 0;
       int x = n % 4;
       if(x == 0) ans = n;
       if(x == 1) ans = 1;
       if(x == 2) ans = n+1;
       if(x == 3) ans = 0;

       cout << ans << endl;
    }
    return 0;
}