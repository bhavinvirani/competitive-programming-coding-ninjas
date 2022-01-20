/* Number Of Factors
Send Feedback
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2 
2
0
8 */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

//* preComputational Functions
void getFactorCount(int arr[])
{
    for (int i = 2; i <= MAX; i += 2)
    {
        arr[i]++;
    }

    for (int i = 3; i <= MAX; i += 2)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j <= MAX; j += i)
            {
                arr[j]++;
            }
        }
    }
}

int primeFactors(int a, int b, int n, int factorCount[])
{  
    int count = 0;
    for(int i = a; i <= b; i++){
        if(factorCount[i] == n){
            count++;
        }
    }
    return count;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;

    int factorCount[MAX] = {0};
    getFactorCount(factorCount);

    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << primeFactors(a, b, n, factorCount) << endl;
    }
    return 0;
}

// vector<bool> getPrimes()
// {
//     vector<bool> primes(MAX, true);
//     primes[0] = false;
//     primes[1] = false;

//     for (int i = 2; i * i <= MAX; i++)
//     {
//         if (primes[i] == true)
//         {
//             for (int j = i * i; j <= MAX; j += i)
//             {
//                 primes[j] = false;
//             }
//         }
//     }
//     return primes;
// }

// int primeFactors(int a, int b, int n)
// {
//     vector<bool> primes = getPrimes();

//     int primeFactorCout[b+1] = {0};
//     for (int i = 2; i <= b; i++){
//         if(primes[i]){
//             for(int j = i; j <= b; j += i){
//                 primeFactorCout[j]++;
//             }
//         }
//     }
//     int count = 0;
//     for(int i = a; i <= b; i++){
//         if(primeFactorCout[i] == n){
//             count++;
//         }
//     }
//     return count;
// }