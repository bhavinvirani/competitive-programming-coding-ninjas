/* AlphaCode-Question
Send Feedback
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input Format:
First line will contain T (number of test case).
Each input is consists of a single line containing the message string
Output Format:
For each test case print the answer % mod (10^9 +7)
Constraints:
1 <= T <= 100
1 <= |S| <= 10^5
sum of length of all string doesn't exceed 5*10^6
Sample Input 1:
3
47974
6349988978
1001
Sample Output 1:
1
1
0 */
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

    //* always returns as integer
    ll output = alphaCode(input, size - 1);
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
    ll * dp = new ll[size + 1]{};
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= size; i++){

        //* current element is not 0
        if(input[i-1] != 0){
            dp[i] = dp[i-1] % M;   //* 

            if(input[i-2]*10 + input[i-1] <= 26){
                if(input[i-1] != 0){
                    dp[i] = (dp[i] + dp[i-2]) % M;
                }
            }
            //* no combination would form
            if(input[i - 1] == 0 && input[i - 2] == 0){
                return 0;
            }
        } else {
            //* this allways produced 00
            if(input[i - 1] == 0 && input[i - 2] == 0){
                return 0;
            }
            //* it can foam 10 20 
            if(input[i-2]*10 + input[i-1] <= 26){
                dp[i] = dp[i-2] % M;

            } else {
                return 0;
            }
        }
    }
    ll n = dp[size];
    delete [] dp;
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
        //* add int elements in array as characters
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