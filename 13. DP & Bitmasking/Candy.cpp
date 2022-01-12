#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<vector<ll>> arr, int n, int child, int mask)
{
    if(child >= n){
        return 1;
    }

    int count = 0;
    for(int i = 0; i < n; i++){
       
        if((!(mask & (1 << i))) && arr[child][i] == 1){
            count += solve(arr, n, child + 1, mask | (1 << i));
        }
    }
    return count;

    // ll dp[(1 << n)];
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1;

    // for (int mask = 0; mask < ((1 << n) - 1); mask++)
    // {

    //     int count = 0;
    //     ll temp = mask;
    //     while (temp)
    //     {
    //         count += temp & 1;
    //         temp >>= 1;
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
            
    //         if ((!(mask & (1 << i))) && arr[count][i] == 1)
    //         {
                
    //             dp[mask | (1 << i)] += dp[mask];
    //         }
    //     }
    // }
    // return dp[(1 << n) - 1]; // 1111
}

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
        vector<vector<ll>> arr(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << solve(arr, n, 0, 0) << endl;
    }
    return 0;
}