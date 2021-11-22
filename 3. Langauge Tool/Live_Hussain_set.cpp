#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    int n,m;
    // n ==> array
    // m ==> Queries
    cin >> n >> m;

    ll arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    queue<ll> q;

    //* take comman variables cause queries are in chronological manner (a[i] > q[i-1])
    //* so satrt counting from where you end last time
    int count_m = 0;
    int end_p = n-1;   //* point to sorted array end

    while(m--){
        int curr_m;
        cin >> curr_m;  //* query point
        int ans;        //* comman ans

        ////* comman count_m (0 < 1)
        for(; count_m < curr_m; count_m++){

            ////* array is not empty && (if queue is empty || last element of array is larger than front of queue)
            
            if(end_p >= 0 && (q.empty() || arr[end_p] >= q.front())){
                ans = arr[end_p];
                end_p--;
            } else {   //* 
                ans = q.front();
                q.pop();
            }

            //* again push to queue
            q.push(ans/2);
        }
        ////* ans ==> which selected from the queue or array
        cout << ans << endl;
    }

    return 0;
}