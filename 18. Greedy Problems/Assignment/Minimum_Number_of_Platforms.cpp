#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// #include "solution.h"
int calculateMinPatforms(int at[], int dt[], int n)
{

    sort(at, at+n);
    sort(dt, dt+n);
    int cur_platforms = 1;
    int ans = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {

        if (at[i] <= dt[j])
        {
            cur_platforms++;
            i++;
        }

        else if (at[i] > dt[j])
        {
            cur_platforms--;
            j++;
        }

        if (cur_platforms > ans){
            ans = cur_platforms;
        }
    }

    return ans;
}

class Runner
{
    int t;
    vector<int> tn;
    vector<vector<int>> at, dt;

public:
    void takeInput()
    {
        cin >> t;

        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            vector<int> tmp(n);
            for (int i = 0; i < n; i++)
            {
                cin >> tmp[i];
            }

            at.push_back(tmp);
            for (int i = 0; i < n; i++)
            {
                cin >> tmp[i];
            }

            dt.push_back(tmp);
            tn.push_back(n);
        }
    }

    void execute()
    {
        vector<int> arrCopy = tn;

        for (int i = 0; i < t; i++)
        {
            int n = tn[i];
            int arrayAt[n], arrayDt[n];
            for (int j = 0; j < n; j++)
            {
                arrayAt[j] = at[i][j];
                arrayDt[j] = dt[i][j];
            }

            int ans = calculateMinPatforms(arrayAt, arrayDt, tn[i]);
        }

        arrCopy.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int n = tn[i];
            int arrayAt[n], arrayDt[n];
            for (int j = 0; j < n; j++)
            {
                arrayAt[j] = at[i][j];
                arrayDt[j] = dt[i][j];
            }
            int ans = calculateMinPatforms(arrayAt, arrayDt, tn[i]);
            cout << ans << endl;
        }
    }
};

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}