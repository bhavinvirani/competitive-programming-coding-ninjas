/* Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output Format:
Output a single integer, maximum sum rectangle for each test case in a newline.
Constraints
1 <= T <= 50
1<=n,m<=100
-10^5 <= mat[i][j] <= 10^5
Sample Input
1
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29 */

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> vec)
{
    int maxSum = INT_MIN, curSum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        curSum += vec[i];
        maxSum = max(maxSum, curSum);
        curSum = (curSum < 0) ? 0 : curSum;
    }
    return maxSum;
}

int findMaxSum(vector<vector<int>> arr, int row, int col)
{
    // int ans = 0;
    // int startx = 0, starty = 0, endx = 0, endy = 0;

    // for (int i = 0; i < row; i++)
    // {
    //     startx = i;
    //     for (int j = 0; j < col; j++)
    //     {
    //         starty = j;
    //         for (int m = 0; m < row; m++)
    //         {
    //             endx = m;
    //             for (int n = 0; n < col; n++)
    //             {
    //                 endy = n;
    //                 int sum = 0;
    //                 for (int a = startx; a <= endx; a++)
    //                 {
    //                     for (int b = starty; b <= endy; b++)
    //                     {
    //                         sum += arr[a][b];
    //                     }
    //                 }
    //                 if (sum > ans)
    //                     ans = sum;
    //             }
    //         }
    //     }
    // }

    //? 2nd approch

    int max_sum_soFar = INT_MIN;
    for(int i = 0; i < row; i++){

        vector<int> temp(row);
        for (int j = i; j < col; j++)
        {
            for (int k = 0; k < row; k++){
                temp[k] += arr[k][j];
            }
            max_sum_soFar = max(max_sum_soFar, kadane(temp));
        }
        
    }

    return max_sum_soFar;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            arr.push_back(tmp);
        }

        int ans;
        ans = findMaxSum(arr, n, m);
        cout << ans << endl;
    }
    return 0;
}