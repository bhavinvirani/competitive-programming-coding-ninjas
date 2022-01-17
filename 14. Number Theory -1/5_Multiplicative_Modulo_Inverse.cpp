#include <bits/stdc++.h>
using namespace std;

/*
    Ax + By = gcd(A, B)  //(Ans)
*/
class Triplet
{
public:
    int x;
    int y;
    int gcd;
};

/* Take A and B and find x and y */
Triplet extendedEuclid(int a, int b)
{
    /*  Ax+By = gcd(A,0)
     Ax+0 = A -> x = 1, y = 0
     Ax = A           // gcd(A,0) == A
     x = 1
     y = 0
    */
    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    // Extended Euclid Algorithm
    /* Bring small answer and make X and Y */
    Triplet smallAns = extendedEuclid(b, a % b);

    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;                        //* x = y
    ans.y = smallAns.x - (a / b) * smallAns.y; //* x - (a/b) * y
    return ans;
}

int mmInverse(int a, int m)
{
    Triplet ans = extendedEuclid(a, m);
    return ans.x;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    return 0;
}