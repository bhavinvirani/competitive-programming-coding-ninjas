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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i].first >> arr[i].second;
        }

        vector<pair<int, int>> v;
        for (int i = 1; i < n; ++i)
        {
            int pts = min(arr[i].first, arr[i - 1].second) - min(arr[0].first, arr[n - 1].second);
            v.push_back({pts, i});
        }
        sort(v.begin(), v.end());

        int index = 0;
        if (v.size() > 0 && v[0].first < 0)
        {
            index = v[0].second;
        }

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            ans += arr[index].first;
            int damage = arr[index].second;

            index = (n + index + 1) % n;

            arr[index].first = max(0, arr[index].first - damage);
        }
        cout << ans << '\n';
    }
    return 0;
}