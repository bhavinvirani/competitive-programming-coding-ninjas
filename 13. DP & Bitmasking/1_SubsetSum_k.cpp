#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    int masks = (1 << n);
    //* for posible mask combinations
    for (int mask = 0; mask < masks; mask++)
    {
        int sum = 0;
        //* to check Jth bit is set or not in corresponding mask
        for (int j = 0; j < n; j++)
        {
            //* check Jth bit
            int x = (mask & (1 << j));
            if (x != 0)
            {
                sum += arr[j];
            }
        }
        if (sum == k)
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}