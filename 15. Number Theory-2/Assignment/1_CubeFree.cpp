/* Find The Cube Free Number
Send Feedback
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number
Input Format:
First line of the test case will be the number of test case T 
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^6
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// basic approch
// void getCubes(int n, vector<ll> &cubes)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         cubes.push_back(i * i * i);
//     }
// }

// void solve(int n, vector<ll> &cubes)
// {
//     int count = 0;
//     int k = 0;
//     bool isCubeFree = true;
//     for (int i = 1; i <= n; i++)
//     {
//         if (cubes[k] == i)
//         {
//             isCubeFree = false;
//             k++;
//             break;
//         }
//         else
//         {
//             count++;
//         }
//     }
//     if (isCubeFree)
//     {
//         cout << count << endl;
//     }
//     else
//     {
//         cout << "Not Cube Free" << endl;
//     }
// }

void getCubes(int n, int arr[])
{
    for (int i = 2; i <= 100; i++)
    {
        for (int j = i * i * i; j <= n; j *= 2)
        {
            arr[j] = -1;
        }
    }
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    
    int t;
    cin >> t;

    int arr[1000001] = {0};
    getCubes(1000001, arr);

    int cubesCount = 1;
    bool isCubeFree = true;
    unordered_map<int, int> m;
    for (int i = 1; i <= 1000000; i++)
    {
        if (arr[i] == 0)
        {
            m[i] = cubesCount;
            cubesCount++;
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        if (!m[n])
        {
            cout << "Not Cube Free" << endl;
        }
        else
        {
            cout << m[n] << endl;
        }
    }
    return 0;
}