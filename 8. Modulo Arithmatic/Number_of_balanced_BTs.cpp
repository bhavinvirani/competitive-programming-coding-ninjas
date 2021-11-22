#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int BBTs(int h){
    if(h == 0 || h == 1) {
        return 1;
    }

    int m = pow(10,9) + 7;
    int x = BBTs(h-1);
    int y = BBTs(h-2);

    ll ansx = (ll)x*x;
    ll ansy = (ll)x*y*2;

    int ans1 = (int)(ansx % m);
    int ans2 = (int)(ansy % m);

    int ans = (ans1 + ans2) % m;

    return ans;
}

int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;
    
    while(t--)
    {
       int h;
       cin >> h;
       int ans;
       ans = BBTs(h);
       
       cout << ans << endl;

    }

    return 0;
}