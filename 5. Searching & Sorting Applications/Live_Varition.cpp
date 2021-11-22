/* We say that two integers x and y have a variation of at least K, if |x − y| ≥ K (the absolute value of their difference is at least K). Given a sequence of N integers a1,a2,...,aN and K, the total variation count is the number of pairs of elements in the sequence with variation at least K, i.e. it is the size of the set of pairs

{(i,j)|1≤i<j≤N and|ai−aj|≥K}

For example if K = 1 and the sequence is 3,2,4 the answer is 3. If K = 1 and the sequence is 3, 1, 3 then the answer is 2.

Your task is to write a program that takes a sequence and the value K as input and computes the total variation count.

Input format
The first line contains two positive integers N and K, separated by a space.

This is followed by a line containing N integers separated by space giving the values of the sequence.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long varition_array(int arr[], int n, int k){
    long count = 0;
    int i = 0;
    int j = 1;
    sort(arr, arr+n);
    
    while(j < n){
        if(arr[j] - arr[i] >= k){
            count += (n-j);
            i++;
        } else {
            j++;
        }
    }
    return count;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    long count = varition_array(arr, n, k);
    cout << count << endl;
    return 0;
}