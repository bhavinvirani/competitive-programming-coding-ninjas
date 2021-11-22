#include<iostream>
using namespace std;

int firstIndex(int arr[], int size, int x) {

    if(size == 0) return -1;
    
    if(arr[0] == x) return 0;
    
    int smallerAns = firstIndex(arr+1, size -1, x);
 
    if(smallerAns == -1) {
        return -1;
    } else {
       return smallerAns + 1;
    } 

}

int lastIndex(int arr[], int size, int x) {

     if(size == 0) return -1;
    
    int smallerAns = lastIndex(arr+1, size -1, x);
    
    if(arr[0] == x && smallerAns == -1) return 0;  // hit only one time when first time number found (reverse order)
    
    if(smallerAns == -1) {                         // still number not found
        return -1;
    } else {
       return smallerAns + 1;
    } 

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
    
    cout << lastIndex(input, n, x) << endl;

}


