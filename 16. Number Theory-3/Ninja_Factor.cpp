#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n,q;
    cin >> n >> q;
    int arr[n];
    vector<ll> a(n+1), dp(n+1,0);

    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 3 || a[i] == 4 || a[i] == 6){
            dp[i] = 1;
        }
        dp[i] += dp[i-1];
    }

    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << endl;
    }



    return 0;
}