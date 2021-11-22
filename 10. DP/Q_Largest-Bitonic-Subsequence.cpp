#include <bits/stdc++.h>
using namespace std;

int L_Bitonic_S(int arr[], int n)
{
    int output[n] = {0};
    vector<int> forward(n,1), backward(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j]){
                forward[i] = max(forward[i], forward[j] + 1);
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(arr[i] > arr[j]){
                backward[i] = max(backward[i], backward[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, forward[i] + backward[i] - 1);
    }
    return ans;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = L_Bitonic_S(arr, n);
        cout << ans << endl;
    }
    return 0;
}