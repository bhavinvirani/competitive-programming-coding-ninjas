// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.

#include <iostream>
#include <algorithm>
using namespace std;

long long merge(int arr[], int start, int m, int end)
{
    int n1 = m - start + 1;
    int n2 = end - m;

    long long L[n1], R[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = start;

    long long sum = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            sum += (L[i] * (n2 - j));
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    return sum;
}

long long mergeSort(int arr[], int start, int end, long long sum = 0)
{
    if (start < end)
    {
        int mid = (start + end - 1) / 2;
        long long c1 = mergeSort(arr, start, mid, sum);
        long long c2 = mergeSort(arr, mid + 1, end, sum);
        sum += merge(arr, start, mid, end) + c1 + c2;
    }
    return sum;
}

long long solve(int A[], int n)
{
    long long sum = mergeSort(A, 0, n - 1);
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(arr, n) << endl;
    }
}
