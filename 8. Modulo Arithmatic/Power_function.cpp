#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = pow(10,9) + 7;


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;
    
    while(t--)
    {
       int x,y;
       cin >> x >> y;

       ll ans = 1;
       for(int i = 1; i <= y; i++){
           ans = (ans * x) % MOD;
       }
       cout << ans << endl;
    }
    return 0;
}