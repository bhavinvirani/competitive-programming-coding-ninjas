#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ll;

void multiply(ll A[2][2], ll M[2][2])
{

    ll firstValue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	ll secondValue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
	ll thirdValue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	ll fourthValue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

    A[0][0] = firstValue % MOD;
    A[0][1] = secondValue % MOD;
    A[1][0] = thirdValue % MOD;
    A[1][1] = fourthValue % MOD;
}
void power(ll A[2][2], ll n)
{
    if (n == 1)
    {
        return;
    }
    power(A, n / 2);
    multiply(A, A);
    if (n % 2 != 0)
    {
        ll F[2][2] = {{1, 1}, {1, 0}};
        multiply(A, F);
    }
}
ll getFibonacci(ll n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    ll A[2][2] = {{1, 1}, {1, 0}};
    power(A, n - 1);
    return A[0][0] % MOD;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {
        ll m,n;
        cin >> m >> n;
        
        cout << (getFibonacci(n + 2)%MOD - getFibonacci(m + 1)%MOD+MOD)%MOD << endl;
    }
}