#include <iostream>
using namespace std;

// int solve(int n)
// {

//     int phi[n + 1];

//     for (int i = 1; i <= n; i++)
//     {
//         phi[i] = i;
//     }

//     for (int i = 2; i <= n; i++)
//     {
//         //* ith is prime number
//         if (phi[i] == i)
//         {
//             phi[i] = i - 1;
//             for (int j = 2 * i; j <= n; j += i)
//             {
//                 phi[j] = (phi[j] * (i - 1)) / i;
//             }
//         }
//     }

//     return phi[n];
// }
// int main()
// {

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         cout << solve(n) << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int res = n;
        
        for(int i = 2; i * i <= n;i++){
            if(n%i == 0){
                res -= res/i;
            	while(n % i == 0) n /= i;
            }
        }
        if(n > 1) res -= res/n;
        
        cout<<res<<"\n";
    }
    return 0;
}