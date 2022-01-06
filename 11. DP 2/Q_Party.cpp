    #include <bits/stdc++.h>
    using namespace std;

    pair<int, int> solve_dp(int n, int w, int fee[], int fun[])
    {   
        //* no parties
        if(n == 0){
            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        // for array
        pair<int, int> zero_pair = make_pair(0, 0);
        //* 2D vector of pair
        vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(w+1, zero_pair));
        
        //* fee, fun
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < w+1; j++)
            {   
                //* fee is less than or equal to budget
                if (fee[i-1] <= j)
                {
                    pair<int, int> c1;
                    c1.first = fee[i-1] + dp[i-1][j - fee[i-1]].first; // fee
                    c1.second = fun[i-1] + dp[i-1][j - fee[i-1]].second; // fun

                    //* not take party situation(above sell)
                    pair<int, int> c2 = dp[i-1][j];

                    if (c1.second > c2.second)
                    {
                        dp[i][j] = c1;
                    }else if(c1.second < c2.second)
                        dp[i][j] = c2;
                    else{
                        if (c1.first <= c2.first)
                        {
                            dp[i][j] = c1;
                        }else
                            dp[i][j] = c2;
                    }
                }else{

                    dp[i][j] = dp[i-1][j];

                }
            }
        }

        // for (int i = 0; i < n+1; i++)
        // {
        // 	for (int j = 0; j < w+1; j++)
        // 	{   
        //         cout << dp[i][j].first << "," << dp[i][j].second << " ";
        // 	}
        //     cout << endl;
        // }


        return dp[n][w];
        
    }

    int main()
    {
        freopen("/home/spy/Desktop/input.txt", "r", stdin);
        freopen("/home/spy/Desktop/output.txt", "w", stdout);

        int n;
        cin >> n;
        int fee[n], fun[n];
        for (int j = 0; j < n; j++)
        {
            cin >> fee[j];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> fun[j];
        }
        int w;
        cin >> w;
        // cout << solve(n, w, fee, fun) << endl;

        pair<int, int> pair;
        pair = solve_dp(n, w, fee, fun);
        cout << pair.first << " " << pair.second << endl;

        return 0;
    }