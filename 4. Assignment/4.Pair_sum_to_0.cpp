#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int ZeroPairSum(int n, vector<int> arr){
    // Write your code here

    //? O(N^2)
    //   int count = 0;
    //     for(int i = 0; i < n-1; i++){

    //         for(int j = i+1; j < n; j++){
    //             if(arr[j] + arr[i] == 0){
    //                 count++;
    //             }
    //     	}
    //     }
    //     return count;


      // Variable to store the count of pairs.
    int count=0;
    
    // Hash-map to store frequency of each element
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    // Iterating the hash-map
    for(auto it = mp.begin(); it != mp.end(); it++){
        
        int curKey = it->first;
        
        // Checking if curKey is not equal to 0
        // Also checking if -curKey exists in the hash-map
        if(curKey!=0 && mp.find(-curKey)!=mp.end()){
            
            // Multiplying frequencies and adding them to count
            count+=(mp[curKey]*mp[-curKey]);
        }
    }
    
    // Handling the border case when array element is equal to 0
    if(mp.find(0)!=mp.end()){
        int f = mp[0];
        // Multiplying f and f-1 and adding it to count
        count+=(f * (f-1));
    }
    
    return count/2;

}

int main() {

    return 0;
}