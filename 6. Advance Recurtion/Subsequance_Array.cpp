/*
Number of APs
Send Feedback
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
 Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// int solve(vector<int> arr, int arri, vector<int> ss)
// {
//     if(arri == arr.size()){
//         int x = ss.size();
//         if(x == 1 || x == 0){
//             return 1;
//         }
//         bool flag = true;
//         for(int i=1; i<x; i++){
//             if(ss[i] < ss[i-1]){
//                 flag = false;
//             }
//         }
//         if(flag){
//             return 1;
//         } else {
//             return 0;
//         }
//     }

//     int option1 = solve(arr, arri + 1, ss);
//     ss.push_back(arr[arri]);
//     int option2 = solve(arr, arri + 1, ss);
//     return option1 + option2;
// }

int solve(vector<int> arr, int n)
{
    //*
    unordered_map<int, int> map[n];

    //* all single digits + empty
    int ans = n + 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            //* at every ith map store every diff count with ith element
            map[i][diff]++;
            (ans++) % MOD;
        }
    }

    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[igit];
            /*
                [3,6,9,12]
                6-3 => 3
                started with 3 and diff 3 + starded with 6(j) and diff 3

             */
            //* 3 => 36 => 369
            //* 
            map[i][diff] = (map[i][diff] % MOD + map[j][diff] % MOD) % MOD;
            ans = (ans + map[j][diff]) % MOD;
        }
    }
    return ans;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> op;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n);
    return 0;
}