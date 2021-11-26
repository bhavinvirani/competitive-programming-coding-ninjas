#include <bits/stdc++.h>
using namespace std;

long count_array(int n, int k, int x){
    //* if n == 1 then
    // first position need to be fild by 1
    long oneCount = 1;
    long nonOneCount = 0;

    for(int i = 1; i < n; i++){
        long preOneCount = oneCount;
        oneCount = nonOneCount * (k-1);
        nonOneCount = preOneCount + (nonOneCount * (k-2));
    }

    //* first position is 1 and also last  position(x) == 1 then return
    if(x == 1){
        return oneCount;
    } 

    //* last possition need to fild with nonOne 
    else {
        return  nonOneCount;
    }
}


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n,k,x;
    cin >> n >> k >> x;

    //* 1st element must be 1st
    //* last element must be xor
    //* all elements must be between 1 to k (inclusive);

    cout << count_array(n,k,x) << endl;
    
    return 0;
}