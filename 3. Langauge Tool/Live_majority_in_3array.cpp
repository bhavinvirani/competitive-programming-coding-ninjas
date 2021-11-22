#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getVoters(int arr[], int n)
{
    sort(arr, arr + n);   
    vector<int> voters;

    for (int i = 0; i < n; i++)
    {
            int count = 0;
            int j = i;      //* form where to check repeat numbers
            while (j < n && (arr[j] == arr[i])){  //* check how many times number was repeated
                count++;
                j++;
            }
            if(count >= 2){
                voters.push_back(arr[i]);
            }

            i = j;        
    }
    return voters;
}

int main()
{   
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int n = n1 + n2 + n3;
    int arr[n];       //* make combine array

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];    //* take combine array input
    }
    vector<int> voters = getVoters(arr, n);

    return 0;
}