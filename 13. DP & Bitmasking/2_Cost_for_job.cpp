#include <bits/stdc++.h>
using namespace std;

// parameters of the function are:
// 1. cost matrix
// 2. number of persons and jobs
// 3. person which has to be assigned a job
// 4. mask (initially zero)
// 5. dp array
int solve(int cost[4][4], int n, int p, int mask, int *dp)
{

    //* all person assigned to job (0 1 2 3)
    if (p >= n)
    {
        return 0;
    }

    //* mask is overlaping with each other
    if (dp[mask] != INT_MAX)
    {
        return dp[mask];
    }

    int minimum = INT_MAX;

    //* check Ith bit of mask
    for (int i = 0; i < n; i++)
    {
        //* id ith bit not set means that job not assigned
        if (!(mask & (1 << i)))
        {
            //* cost, n, find job for next person, set current bit of mask cause it aassigned job
            int ans = solve(cost, n, p + 1, mask | (1 << i), dp) + cost[p][i];
            minimum = min(minimum, ans);
        }
    }
    dp[mask] = minimum;
    return minimum;
}

int solve_iter(int cost[4][4], int n)
{
    int dp[(1 << n)];
    for(int i = 0; i < (1 << n); i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    //* mask from 0000 to 1111
    for (int mask = 0; mask < ((1 << n) - 1); mask++)
    {

        //* count number of set bits in mask
        //* if set bit 2 then job asigned to first 2 person
        int count = 0;
        int temp = mask;
        while (temp)
        {
            count += temp & 1;
            temp >>= 1;
        }

        //* check job assigned or not in mask by checking se bits
        for (int i = 0; i < n; i++)
        {
            //* if current bit is not asign then we can assign to countTH person
            if (!(mask & (1 << i)))
            {   
                //* set Ith bit
                //* minimum current mask + cost of perticular person and at perticular mask
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + cost[count][i]);
            }
        }
    }
    return dp[(1 << n) - 1]; // 1111
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n = 4;
    int inital_person = 0;
    int inital_mask = 0; //* 0000
    int cost[4][4] = {{10, 4, 6, 5}, {1, 15, 12, 8}, {7, 8, 9, 3}, {15, 13, 4, 10}};

    int *dp = new int[1 << 4];
    for (int i = 0; i < (1 << 4); i++)
    {
        dp[i] = INT_MAX;
    }
    cout << solve(cost, n, inital_person, inital_mask, dp) << endl;

    cout << solve_iter(cost, n) << endl;

    return 0;
}