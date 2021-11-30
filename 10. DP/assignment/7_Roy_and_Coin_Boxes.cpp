/* Roy and Coin Boxes
Send Feedback
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.
After M days, Roy has a query: How many coin boxes have at least X coins.
He has Q such queries.
Input Format:
First line will contain T (number of test case), format of each test case follows
First line contains two space separated integers N and M (N - number of coin boxes, M - number of days). Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.
Output Format:
For each query of each test case output the result in a new line.
Constraints:
1 <= T <= 10
1 ≤ N ≤ 10000
1 ≤ M ≤ min(10000, N)
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 10000
1 ≤ X ≤ N
Sample Input
1
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4 */

//? give answer in O(1) time

#include <bits/stdc++.h>
using namespace std;

int find(int boxes[], int query, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(boxes[i] >= query){
            ans++;
        }
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
        int n, days;
        cin >> n >> days;
        int boxes[n + 1] = {0};

        //* maintains the start and end indexes
        int start[n+1] = {0};
        int end[n+1] = {0};
        for (int i = 0; i < days; i++)
        {      
            int l,r;
            cin >> l >> r;
            start[l]++;
            end[r]++;
        }

        //* final array after adding coins
        for(int i = 1; i <= n; i++){
            boxes[i] = (start[i] - end[i - 1]) + boxes[i-1];
        }

        //* store frequency
        int coins[n+1] = {0};
        for (int i = 0; i <= n; i++)
        {
            coins[boxes[i]]++;
        }

        //* atlest
        //* left to right sum
        for(int i = n-1; i >= 0; i--){
            coins[i] += coins[i+1];
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++){
            int query;
            cin >> query;
            cout << coins[query] << endl;
        }
        cout << endl;

       
        // for(int i = 0; i < q; i++){
        //     cout << find(boxes, query[i], n) << endl;
        // }
        // cout << endl;

        
    }

    return 0;
}