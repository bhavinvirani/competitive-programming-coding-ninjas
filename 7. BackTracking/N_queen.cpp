#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPosible(int n, int row, int col)
{
    // same column
    for(int i = row - 1; i >= 0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }

    // upper left digonal
    for(int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

     // upper right digonal
    for(int i = row - 1, j = col + 1; i >=0 && j < n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void nQueenHelper(int n, int row)
{

    //* Base case
    if (row == n)
    {
        //* we have reached at ome solution
        //* print the bord matrix
        //* return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    //* place at all the possible positions and move to smaller problem
    for (int col = 0; col < n; col++)
    {

        if (isPosible(n, row, col))
        {

            board[row][col] = 1;
            nQueenHelper(n, row + 1);
            board[row][col] = 0;
        }
    }
    return;
}

void n_queen(int n)
{
    //* make global array with all zeros
    memset(board, 0, 11 * 11 * sizeof(int));

    nQueenHelper(n, 0);   //* in which row to insertz
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int N;
    cin >> N;

    n_queen(N);

    return 0;
}