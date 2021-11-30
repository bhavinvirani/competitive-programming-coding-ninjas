#include <bits/stdc++.h>
using namespace std;


int min_cost(int** input, int si, int sj, int ei, int ej) {
    //* target reached
    if(si == ei && sj == ej){
        return input[ei][ej];
    }

    //* whene bound breached 
    if(si > ei || sj> ej){
        return INT_MAX;
    }

    //* function call in all thre directions
    int option1 = min_cost(input, si + 1, sj, ei, ej);
    int option2 = min_cost(input, si, sj + 1, ei, ej);
    int option3 = min_cost(input, si + 1, sj + 1, ei, ej);

    //* current cost + previous minimum path cost
    return input[si][sj] + min(option1, min(option2, option3));
}

int min_cost_memo(int** input, int si, int sj, int ei, int ej, vector<vector<int>> memo) {
    if(si == ei && sj == ej){
        return input[ei][ej];
    }
    //* whene bound breached 
    if(si > ei || sj> ej){
        return INT_MAX;
    }
    if(memo[si][sj] > -1){
        return memo[si][sj];
    }

    int option1 = min_cost(input, si + 1, sj, ei, ej);
    int option2 = min_cost(input, si, sj + 1, ei, ej);
    int option3 = min_cost(input, si + 1, sj + 1, ei, ej);

    memo[si][sj] = input[si][sj] + min(option1, min(option2, option3));
    //* current cost + previous minimum path cost
    return input[si][sj] + min(option1, min(option2, option3));
}

int min_cost_iter(int** input, int row, int col) {

    vector<vector<int>> dp(row, vector<int>(col));

    //* target element
    dp[row-1][col-1] = input[row-1][col-1];

    //* last column cost (current row + next row)
    for(int i = row-2; i >= 0; i--) {
        dp[i][col-1] = input[i][col -1] + dp[i + 1][col - 1];
    }
    //* last row
    for(int i = col-2; i >= 0; i--) {
        dp[row-1][i] = input[row-1][i] + dp[row-1][i + 1];
    }

    //* current cost + minimum of all three cost
    for(int i = row-2; i >= 0; i--) {
        for(int j = col-2; j >= 0; j--) {
            dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
        }
    }
    return dp[0][0];

    
}

int main() {

    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	// cout << min_cost(input, 0,0,2,2) << endl;

    // vector<vector<int>> memo(3, vector<int>(3, -1));
	// cout << min_cost_memo(input, 0,0,2,2, memo) << endl;

    //* destination index(3,3)
	cout << min_cost_iter(input,3,3) << endl;
	delete [] input[0];
	delete [] input[1];
	delete [] input[2];
	delete [] input;
}