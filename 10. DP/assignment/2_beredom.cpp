/* Boredom
Send Feedback
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
First line will contain T (number of test case), each test case is consists of two line.
Line 1: Integer N 
Line 2: A list of N integers
Output Format :
For each test case print maximum points, Gary can receive from the Game setup in a newline.
Constraints :
 1 <= T <= 50
 1 <= N <= 10^5
 1 <= A[i] <= 1000
Sample Input :
1
2
1 2
Sample Output :
2 */

#include <bits/stdc++.h>
using namespace std;

int max_points(int arr[], int n)
{
    //* frequencies of elements
    int feq[10005] = {0};
    int dp[10005] = {0};
    for (int i = 0; i < n; i++)
    {   
        feq[arr[i]]++;
    }   

    //* for 1 answer is 1 :- (1 * N) == 1;
    dp[1] = feq[1];


    for (int i = 2; i <= 1000; i++)
    {
        //* for any digit the are two choices
        //* take or not
        //* last answer or (current frequency of that element * current + dp[i-2])
        dp[i] = max(dp[i-1], dp[i-2] + (i * feq[i]) );
    }0
    return dp[1000];
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

        cout << max_points(arr, n) << endl;
    }
    return 0;
}