#include <bits/stdc++.h>
using namespace std;

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n)
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        bool isPosible = false;
        if (gas[i] >= cost[i])
        {
            int gasLeft = 0;
            for (int j = i; j < i + n; j++)
            {

                gasLeft += gas[j % n];
                gasLeft -= cost[j % n];
                if (gasLeft < 0)
                {
                    break;
                }
                if (j == (i + n) - 1)
                {
                    ans = i;
                    return ans;
                }
            }
        }

    }
    return -1;
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

        vector<int> gas(n), cost(n);

        for (int i = 0; i < n; i++)
        {
            cin >> gas[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> cost[i];
        }

        cout << minimumStartingIndex(gas, cost, n) << endl;
    }
}