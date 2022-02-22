#include <bits/stdc++.h>
using namespace std;

void solve(int s, int n)
{

    int arr[n] = {0};
    int sum = s - 1;
    for (int i = n - 1; i > 0; i--)
    {

        
        if (sum < 9)
        {
            arr[i] = sum;
            sum = 0;
        }
        else if (sum >= 9)
        {
            arr[i] = 9;
            sum -= 9;
        }
    }
    
    arr[0]=sum+1;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {
        int s, d;
        cin >> s >> d;
        solve(s, d);
    }
    return 0;
}