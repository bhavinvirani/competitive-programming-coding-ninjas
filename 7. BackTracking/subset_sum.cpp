#include <bits/stdc++.h>
using namespace std;

int subset_sum(int arr[], int k, int n, int sum)
{
    int count = 0;
    if (n == 0)
    {
        if(sum == k)
            return 1;

        return 0;
    }

    if (arr[0] > k)
    {
        count += subset_sum(arr + 1, k, n - 1, sum);
    }
    else
    {
        count += subset_sum(arr + 1, k, n - 1, sum);
        count += subset_sum(arr + 1, k, n - 1, sum + arr[0]);
    }

    return count;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = subset_sum(arr, k, n, 0);

        cout << ans << endl;
    }

    return 0;
}
