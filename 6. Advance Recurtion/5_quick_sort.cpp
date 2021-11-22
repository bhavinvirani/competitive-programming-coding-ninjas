#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (pivot >= arr[i]){
            count++;
        }
    }
    
    int pivotIndex = low + count;
    swap(arr[low], arr[pivotIndex]);


    int i = low, j = high;

    while (i <= pivotIndex && j >= pivotIndex)
    {
        while(i <= pivotIndex && arr[i] <= pivot){
            i++;
        }
        while(j >= pivotIndex && arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int c = partition(arr, low, high);
        quickSort(arr, low, c - 1);
        quickSort(arr, c + 1, high);
    }
    
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }

    return 0;
}