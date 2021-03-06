/* Angry Children
Send Feedback
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
    for(j=i;j<n;j++)
        unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format:
First line will contain T(number of test cases), and each test case consists of two lines.
The first line contains two space-separated integers N and K.
The second line will contain N space-separated integers, where Ith integer denotes the candy in the Ith packet.
Output Format:
For each test case print a single integer which will be minimum unfairness in newline.
Constraints
1 <= T <= 10
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^6
Sample Input
1
7 3
10 100 300 200 1000 20 30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way. */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> vec;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end());

        ll sum[n];
        sum[0] = vec[0];
        //* track of sum till ith element
        for (ll i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + vec[i];
        }

        //* cost of first K
        ll start = 0;
        ll end = k-1;
        ll minimum = 0;
        for (ll i = 1; i <= end; i++)
        {
            //* oldCost + (previous entries * current) - previous sum
            minimum += ((i * vec[i]) - sum[i - 1]);
        }

        //* skip 1 and then next k elements
        ll temp = 0;
        temp = minimum;
        start++;
        end++;
        while (end < n)
        {
            temp += ((end - start) * vec[end] - (sum[end - 1] - sum[start - 1]));
            temp -= ((sum[end - 1] - sum[start - 1])) - (end - start) * vec[start - 1];
            minimum = min(minimum, temp);
            start++;
            end++;
        }
        cout << minimum << endl;
    }
    return 0;
}