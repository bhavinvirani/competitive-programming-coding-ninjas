#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    //* equal value then less weight
    return a.first < b.first;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pieces(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pieces[i].first >> pieces[i].second;
    }

    sort(pieces.begin(), pieces.end(), compare);

    multiset<int> m;
    int weight;
    for (int i = 0; i < k; i++)
    {
        cin >> weight;
        m.insert(weight);
    }

    long ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (m.empty())
        {
            break;
        }
        //* find exact less valued bag available to current jwelary weight
        else if (m.lower_bound(pieces[i].first) != m.end())
        {
            ans += pieces[i].second;
            m.erase(m.lower_bound(pieces[i].first));
        }
    }
    cout << ans;
    return 0;
}