#include <bits/stdc++.h>
using namespace std;

int magic_grid(vector<vector<int>> grid, int si, int sj, int row, int col)
{

    if (si == row - 1 && sj == col - 1)
    {
        return 1;
    }

    //* out of bounds
    if (si >= row || sj >= col)
    {
        return INT_MAX;
    }

    // right call
    int right = magic_grid(grid, si, sj + 1, row, col);
    if (right != INT_MAX)
    {
        right -= grid[si][sj + 1];
    }

    // down call
    int down = magic_grid(grid, si + 1, sj, row, col);
    if (down != INT_MAX)
    {
        down -= grid[si + 1][sj];
    }

    int current_pos_cost = min(right, down);

    if (current_pos_cost <= 0)
    {
        return 1;
    }
    return current_pos_cost;
}

int magic_grid_memo(vector<vector<int>> grid, int si, int sj, int row, int col, vector<vector<int>> memo)
{

    if (si == row - 1 && sj == col - 1)
    {
        return 1;
    }

    //* out of bounds
    if (si >= row || sj >= col)
    {
        return INT_MAX;
    }
    if(memo[si][sj] != -1){
        return memo[si][sj];
    }

    // right call
    int right = magic_grid(grid, si, sj + 1, row, col);
    if (right != INT_MAX)
    {
        right -= grid[si][sj + 1];
    }

    // down call
    int down = magic_grid(grid, si + 1, sj, row, col);
    if (down != INT_MAX)
    {
        down -= grid[si + 1][sj];
    }

    int current_pos_cost = min(right, down);

    if (current_pos_cost <= 0)
    {
        memo[si][sj] = 1;
        return 1;
    }
    memo[si][sj] = current_pos_cost;
    return current_pos_cost;
}



int magic_grid_dp2(vector<vector<int>> grid, int row, int col)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));

    dp[row][col - 1] = 1;
    dp[row - 1][col] = 1;

    for(int i = row - 1; i >= 0; i--){
        for(int j = col - 1; j >= 0; j--){
            //* at current position how much life we need to further survive
            //* minimum of left and right ans subtract that position's value from
            //* if it less than 0 then put 1 cause atlest we ned 1 life to survive
            int need = min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j];
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }

    
    
    return dp[0][0];
}

int magic_grid_dp(vector<vector<int>> grid, int row, int col)
{
    int dp[row][col];
    
    //* how much depth at that position
    //* abs() + 1;
    for(int i = row-1; i >=0; i--){
        for(int j = col-1; j >= 0; j--){

            if(i == row-1 && j == col-1){
                dp[i][j] = 0;
            }
            
            //* last row
            else if(i == row -1){
                dp[i][j] = min(0, grid[i][j] + dp[i][j + 1]);
            }

            //* last column
            else if(j == col-1){
                dp[i][j] = min(0, grid[i][j] + dp[i + 1][j]);
            } 
            else {
                dp[i][j] = min(0, grid[i][j] + max( dp[i + 1][j], dp[i][j + 1]));
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    return abs(dp[0][0]) + 1;
    
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> grid;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
            temp.clear();
        }
        //* recursive function
        // int ans = magic_grid(grid, 0, 0, row, col);

        //* memoization
        // vector<vector<int>> memo(row, vector<int>(col, -1));
        // int ans = magic_grid_memo(grid, 0, 0, row, col, memo);

        //* DP
        int ans = magic_grid_dp(grid, row, col);

        // int ans = magic_grid_dp2(grid, row, col);
        

        cout << ans << endl;
    }
    return 0;
}