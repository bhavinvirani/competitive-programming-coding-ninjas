#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef map<string,int> MPSI;
typedef set<int> SETI;



long long getInversions_base(long long *a, int n){
    //* O(n^2)
    long long count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                count++;
            }
        }
    }
    return count;
}


long long merge(long long *arr, int start, int mid, int end){
    
    long long count = 0;
    int temp[end-start + 1];
    int  i = start;
    int  j = mid;
    int  k = 0;
    
    while (i < mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }
    
    while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
    
    for(int i=start, k=0; i<=end; i++, k++)
	{
		arr[i]=temp[k];
	}
    
    
    return count;
}


long long merge_sort(long long *arr, int start, int end){
    long long count = 0;
    if (start < end){
        int mid = (start + end)/2;
        long long count_left = merge_sort(arr, start, mid);
        long long count_right = merge_sort(arr, mid + 1, end);
        long long count_merge = merge(arr, start, mid + 1, end);
        
        return count_left + count_right + count_merge;
    }
    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long count = merge_sort(arr, 0, n-1);
    return count;
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}