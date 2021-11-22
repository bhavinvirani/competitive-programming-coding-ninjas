#include <iostream>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;

long getTimeInMicroSecond(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void selctionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = arr[i];
        int min_index = i;
        for(int j = i + 1; i < n; j++){
            if(arr[j] < min){
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
        
    }
    
}

int main() {
    // for(int n = 10; n <= 100; n *= 10){
    //     int arr[n];
    //     long startTime, endTime;
    //     for(int i = 0; i < n; i++){
    //         arr[i] = n-i;
    //     }
    //     startTime = getTimeInMicroSecond();
    //     selctionSort (arr, n);
    //     endTime = getTimeInMicroSecond();

    //     cout << "SelectionSort n = " << n << " time = " << endTime - startTime << endl;
    // }
    cout << "ok";
    return 0;
}
