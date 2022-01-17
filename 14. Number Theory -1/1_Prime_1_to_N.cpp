//* 1 to N prime numbers
#include <bits/stdc++.h>
using namespace std;

//* Basic approch
bool checkPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return true;
    }
    return false;
}

//* (2) optimized version
bool isPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) //* i*i <= n
    {
        if (n % i == 0)
        {
            //* j == root(n)	EX. (5 * 5) (1 * 1)
            if (i == sqrt(n))
            {
                count++;
            }
            else
            {
                count += 2;
            }
        }
    }

    if (count == 2)
    {
        // cout << n << " ";
        return true;
    }
    return false;
}

//* (3) Optimal solution

bool chekcPrimeOptimal(int n)
{
    if (n == 0 || n == 1)
        return false;

    //* if divisible by any between [2 to sqrt(n)]
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrime(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (chekcPrimeOptimal(i))
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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        // cout << checkPrime(n) << endl;
        // cout << isPrime(n) << endl;

        // int count = countPrime(n);
        // cout << count << endl;
    }
    return 0;
}