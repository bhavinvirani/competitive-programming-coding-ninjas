/*
    Ninja and Flowers
Send Feedback
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
Input Format:
The only line of input will contain an integer N (number of flowers).
Output Format:
In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
Constraints:
1 <= N <= 2*10^5
Sample Input:
4
Sample Output:
2
1 3
*/

/* Here you only need to find the value of prime numbers and just print nunberof primes and n-number of primes */
#include <bits/stdc++.h>
using namespace std;

void getPrimes(int n, bool *primes)
{
    for (int i = 2; i * i < n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

int solve(int n)
{
    bool primes[n + 1];
    for (int i = 0; i <= n; i++)
    {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    getPrimes(n, primes);

    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (primes[i])
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

    int n;
    cin >> n;
    //* n+1 because we need are paying n+1 prise(i+1)
    int numberOfPrimes = solve(n+1);

    //* minimum 2 boxex will required
    cout << 2 << endl;

    //* increasing order
    if (n-numberOfPrimes < numberOfPrimes)
    {
        cout << n-numberOfPrimes << " " << numberOfPrimes;
    }
    else
    {
        cout << numberOfPrimes << " " << n-numberOfPrimes;
    }

    return 0;
}