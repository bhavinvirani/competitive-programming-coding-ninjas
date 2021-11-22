#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = pow(10, 9) + 7;

ll alphaCode(int *input, int size)
{
    if (size == 0 || size == 1)
    {
        return 1;
    }

    ll output = alphaCode(input, size - 1) % M;
    if (input[size - 2] * 10 + input[size - 1] <= 26)
    {
        output += alphaCode(input, size - 2) % M;
    }
    return output % M;
}

ll alphaCode_memo(int *input, int size, ll *memo)
{
    if (size == 0 || size == 1)
    {
        return 1;
    }

    if (memo[size] > 0)
    {
        return memo[size];
    }

    ll output = 0;

    if (input[size - 1] != 0)
    {
        output = alphaCode_memo(input, size - 1, memo) % M;
        if (input[size - 2] * 10 + input[size - 1] <= 26)
        {
            if(input[size - 2] != 0){
                output += alphaCode_memo(input, size - 2, memo) % M;
            }
        }
        if(input[size - 1] == 0 && input[size - 2] == 0){
            return 0;
        }
    } else {
         if (input[size - 2] * 10 + input[size - 1] <= 26)
        {            
                output += alphaCode_memo(input, size - 2, memo) % M;
        } else {
            return 0;
        }
        if(input[size - 1] == 0 && input[size - 2] == 0){
            return 0;
        }
    }


    memo[size] = output;
    return output;
}

ll alphaCode_iter(int input[], int size){
    ll * ans = new ll[size + 1]{};
    ans[0] = 1;
    ans[1] = 1;

    for(int i = 2; i <= size; i++){

        //* current element is not 0
        if(input[i-1] != 0){
            ans[i] = ans[i-1] % M;   //* 

            if(input[i-2]*10 + input[i-1] <= 26){
                if(input[i-1] != 0){
                    ans[i] = (ans[i] + ans[i-2]) % M;
                }
            }
            if(input[i - 1] == 0 && input[i - 2] == 0){
                return 0;
            }
        } else {
            if(input[i-2]*10 + input[i-1] <= 26){
                ans[i] = ans[i-2] % M;

            } else {
                return 0;
            }
            if(input[i - 1] == 0 && input[i - 2] == 0){
                return 0;
            }
        }
    }
    ll n = ans[size];
    delete [] ans;
    return n;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        string n;
        cin >> n;
        if (n == "0")
        {
            return 0;
        }
        int *num_arr = new int[n.size() + 1];
        for (int i = 0; i < n.size(); i++)
        {
            num_arr[i] = n[i] - '0';
        }

        // cout << alphaCode(num_arr, n.size()) << endl;
        // ll memo[n.size() + 1] = {0};
        // cout << alphaCode_memo(num_arr, n.size(), memo) << endl;
        cout << alphaCode_iter(num_arr, n.size()) << endl;
    }
    return 0;
}