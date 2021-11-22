#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkNumber(int arr[], int size, int x) {

	if(arr[0] == x) return true;
    if(size == 1) return false;
    
    bool foundInSmallerArray = checkNumber(arr + 1, size -1, x);
    return foundInSmallerArray;
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}