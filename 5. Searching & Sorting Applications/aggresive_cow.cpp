#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int aggresiveCow_baseAproch(int arr[], int n, int cow)
{
    //* O(D*N)
    // D == possibile max distance
    // N = number of stalls (to check distance)

    int max_dist = 0;
    for (int i = 1; i <= arr[n - 1] - arr[0]; i++)
    {
        int count = 1;
        int last_pos = 0;
        for (int j = 1; j < n; j++)
        {
            if (arr[j] - arr[last_pos] >= i)
            {
                count++;
                last_pos = j;
                if (count >= cow)
                {
                    max_dist = i;
                    break;
                }
            }
            if (j == n && j < 3)
            {
                return max_dist;
            }
        }
    }
    return max_dist;
};



int aggresiveCow_Binary(int arr[], int n, int cows)
{
    int max_dist = 0;
    int left = 0, right = arr[n-1] - arr[0];

    while (left <= right){
        int mid = (left + right)/2;
        int last_pos = 0, count = 1;
        int i = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[last_pos] >= mid)
            {
                count++;
                last_pos = i;
                if (count == cows)   //* all cows placed
                {
                    max_dist = mid;
                    break;
                }
            }
        }
        if(count < cows){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        
    }
    return max_dist;
    
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n_stall, cows;
        cin >> n_stall >> cows;
        int stall[n_stall];
        for (int i = 0; i < n_stall; i++)
        {
            cin >> stall[i];
        }
        // int ans = aggresiveCow_baseAproch(stall, n_stall, cows);
        int ans = aggresiveCow_Binary(stall, n_stall, cows);
        cout << ans << endl;
    }

    return 0;
}