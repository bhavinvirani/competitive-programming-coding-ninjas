#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int t;
    cin >> t;
    
    while(t--)
    {
       int n;
       cin >> n;
       vector<int> vec(n);
       for(int i = 0; i < n; i++) {
           cin >> vec[i];
       }
       sort(vec.begin(), vec.end());
       int min = INT_MAX;
       for(int i = 1; i < n;i++){
           if(vec[i]-vec[i-1] < min){
               min = vec[i]-vec[i-1];
           }
       }
       cout << min << endl;
    }
    return 0;
}