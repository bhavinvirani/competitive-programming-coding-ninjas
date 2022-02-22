#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {int n; cin >> n;
		vector<int> arr(n+1);
		for(int i = 1 ; i <= n ; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin()+1, arr.end());
        // for(auto i : arr){
        //     cout << i << " ";
        // }

		vector<int> dp(n+1, 0);

		int ans = 0;
		for(int i = 1 ; i <= n ; ++i) {
			if(i - arr[i] >= 0) {
				dp[i] = max(dp[i-1], dp[i-arr[i]] + 1);
			}
			else {
				dp[i] = dp[i-1];
			}
		}

		cout << dp[n] << endl;
        
    }
    return 0;
}