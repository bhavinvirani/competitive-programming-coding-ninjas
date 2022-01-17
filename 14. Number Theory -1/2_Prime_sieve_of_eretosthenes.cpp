#include <bits/stdc++.h>
using namespace std;

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

//! sieve of eretosthenes

int countPrime(int n)
{
    vector<bool> vec(n + 1, true);

    // make 0 and 1 false (Nor Prime)
    vec[0] = false;
    vec[1] = false;

    // check from 2 to sqrt(n)
    /*
        n = 25, just need to wor for till 5 and we'll get all prime numbers
    */
    for (int i = 2; i <= sqrt(n); i++)
    {
        //* if true at Ith element then and only then check for prime`
        if (vec[i] == true)
        {
            // if (chekcPrimeOptimal(i))
            // {
                //* If i is prime make all multiples of i false
                /*
                    start with (i * i)
                    because (3*2) coverd before in (2*3)
                    EX. 5 => 5*2  => 2 * 5
                             5*3  => 3 * 5
                             5*4  => 2 * 10 (Not in 4*5)

                */

                for (int k = i * i; k <= n; k += i)
                {
                    vec[k] = false;
                }
            // }
        }
    }
    int count = 0;
    for (auto i : vec)
    {
        if (i)
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

    cout << countPrime(n) << endl;

    return 0;
}