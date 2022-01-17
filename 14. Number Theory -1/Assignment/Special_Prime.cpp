/*
    Special Prime
Send Feedback
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.
Input Format:
An integer N.
Output Format:
Print the number of special primes
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

void getPrimes(int n, bool *primes)
{
    memset(primes, true, 1000001);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

int specialPrime(int n)
{
    bool primes[1000001];
    getPrimes(n, primes);

    int count = 0;

    //* 2 and 3 is not possible
    // for (int i = 2; i < x; i++)
    // {
    //     for (int j = 0; j < i - 1; j++)
    //     {
    //         if ((primes[j] + primes[j + 1]) + 1 == primes[i])
    //             count++;
    //     }
    // }

    int sums[n+1] = {0};
    int index = 0;

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            sums[index] += i;
            sums[index + 1] += i;
            index++;
        }
    }

    for (int i = 1; i <= n; i++)
    {   
        //* if any prime[] == sum + 1 and that sum + 1 <= n
        if (primes[sums[i] + 1] == true && sums[i] + 1 <= n)
        {

            count++;
        }
    }

    return count;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n = 0;
    cin >> n;

    cout << specialPrime(n);

    return 0;
}
