// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distribute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He wants to distribute them in a way such that:
// 1. All students get an equal number of candies.
// 2. All the candies which a student gets must be from a single box only.
// As he wants to make all of them happy so he wants to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.

// Input
// First-line contains T the number of test cases. 
// The first line of each test case contains N and K.
// Next line contains N space-separated integers, ith of which is the number of candies in the ith box.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max(int arr[], int n, int k)
{
    int ans = 0;
    int minimum = 1, maximum = arr[n - 1];

    if (k == 1)
    {
        ans = maximum;
    }
    else
    {

        // for(int i = minimum; i <= maximum; i++){
        //     int temp = 0;
        //     for (int j = 0; j < n; j++)
        //     {
        //         temp += arr[j]/i;
        //         if(temp >= k){
        //             break;
        //         }
        //     }
        //     if(temp < k){
        //         break;
        //     }
        //     ans = i;
        // }

        while (minimum <= maximum)
        {
            int mid = (minimum + maximum) / 2;
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                temp += arr[i] / mid;
                if (temp >= k)
                {
                    ans = mid;
                    break;
                }
            }
            if (temp >= k)
            {
                minimum = mid + 1;
            }
            else
            {
                maximum = mid - 1;
            }
            
        }
    }

    return ans;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

        sort(arr, arr + n);

        int ans = find_max(arr, n, k);
        cout << ans << endl;
    }

    return 0;
}

// 3
// 5 4
// 365 228 993 898 943
// 10 93748
// 73123 73611 73899 78999 79898 78878 76789 77777 77770 78900
// 8 2332
// 3000 2600 2800 2900 2839 2992 2099 2967

// 496
// 8
// 9
