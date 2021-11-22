#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int a[], int n){

    if(n == 0 || n == 1) return true;   // Base case

    if(a[0] > a[1]) return false;       // checking first element of array

    bool isSmallerSorted = is_sorted(a+1, n - 1);   // checking for smaller array 

    return isSmallerSorted;


//* Option 2

    // if(n == 0 || n == 1) return true;   // Base case

    // bool isSmallerSorted = is_sorted(a + 1, n - 1);

    // if(!isSmallerSorted){
    //     return false;
    // }
    // if(a[0] > a[1]){
    //     return false;
    // } else {
    //     return true;
    // }


}

int main() {
    
    return 0;
}