#include <bits/stdc++.h>
using namespace std;

bool isSet(int n, int i)
{
    //* option 1
    bool x = n & (1 << i);
    if (x)
    {
        return x;
    }
    else
    {
        return false;
    }

    // int x = n >> i - 1;
    // //* option 2
    // cout << (x & 1) << endl;  //? 1 & 1 => 1
    // cout << (x | 0) << endl;  //? 1 | 0 => 1 ()
    // cout << (x ^ 0) << endl;  //? 1 ^ 0 => 1 (not same)
}

void toogle(int n, int i)
{
    //* xor
    int x = n ^ (1 << i);
    cout << x << endl;
}
void odd_even(int n){
    if(n & 1){
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
}
void set(int n, int i){
    n |= (1 << i);
    cout << n << endl;
}
void unSet(int n, int i){
    n &= ~(1 << i);
    cout << n << endl;
}

void check_power_2(int n){
    if(n & n-1){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}



int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n, i;
    cin >> n >> i;

    // cout << isSet(n, i) << endl;
    odd_even(8);
    return 0;
}