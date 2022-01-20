#include <bits/stdc++.h>
using namespace std;

vector<bool> getPrimes(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (primes[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int superPrime(int n)
{
    vector<bool> primes = getPrimes(n);
    int primeCount[n + 1] = {0};

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primeCount[j]++;
            }
        }
    }

    int count = 0;
    for (auto i : primeCount)
    {
        if (i == 2)
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
    cout << superPrime(n);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// bool isPrime(int n){
//     if(n == 0 || n == 1) return false;

//     for(int i = 2; i <= sqrt(n); i++) {
//         if(n % i == 0) return false;
//     }
//     return true;
// }

// bool isSuperPrime(int n)
// {
//     int count = 0;
//     for (int i = 2; i <= n/2; i++)
//     {
//         if(isPrime(i) && n%i == 0) count++;
//     }
//     if(count == 2) return true;
//     return false;

// }

// int main()
// {
//     freopen("/home/spy/Desktop/input.txt", "r", stdin);
//     freopen("/home/spy/Desktop/output.txt", "w", stdout);

//     int n;
//     cin >> n;

//     int count = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         if (isSuperPrime(i))
//         {
//             // cout << i << endl;
//             count++;
//         }
//     }
//     cout << endl << "Total SP: " <<  count;

//     return 0;
// }