#include<bits/stdc++.h>
using namespace std;

void merge1(int arr[], int start, int mid, int end){
    
    int n1 = (mid - start) + 1;
    int n2 = (end - mid);
    int a[n1], b[n2];
    
    for(int i = 0; i < n1; i++){
        a[i] = arr[start + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = arr[i + mid + 1];
    }
    
    int i = 0, j = 0, k = start;
    
    while (i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
    
    while(i < n1){
        arr[k++] = a[i++];
    }
    while(j < n2){
        arr[k++] = b[j++];
    }
}


void merge2(int arr[], int start, int mid, int end){
    
   	int temp[end-start + 1];
    int i = start, j = mid + 1, k = 0;
    
    while (i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
    for(int i = start, k = 0; i <= end; i++, k++ ){
        arr[i] = temp[k];
    }
}


void merge_sort(int arr[], int start, int end){
    
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        // merge1(arr, start, mid, end);
        merge2(arr, start, mid, end);
        
        
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
int main(){
    
    // write your code here
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int arr[n];
        
    	for(int i = 0; i < n; i++){
    	    cin >> arr[i];
    	}
    	
    	merge_sort(arr, 0, n-1);
        
		printArray(arr, n);
    }
    
    return 0;
}