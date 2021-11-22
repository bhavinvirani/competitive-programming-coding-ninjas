/* Sorting the Skills

There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills, which is denoted with help of an integer. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’. He can swap the skills as long as the absolute difference between their skills is 1. You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:
First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ integers.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
        {
            cin >> arr[i];
        }

        bool is_possible = true;
        int i = 0, j = 1;

        while (i < n && j < n)
        {
            // adjacent elements is lrge and difference is 1
            if(arr[i] == arr[j] + 1){
                swap(arr[i], arr[j]);
                while(i > 0 && arr[i] == arr[i - 1] - 1){
                    swap(arr[i], arr[i-1]);
                    i--;
                }
                i = j;
                j = i + 1;
            } else {
                i++;
                j++;
            }
        }
        
        for (int i = 1; i < n ; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                is_possible = false;
                break;
            }
        }

        if (is_possible)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;

}
