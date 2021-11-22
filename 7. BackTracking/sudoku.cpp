#include <bits/stdc++.h>
using namespace std;
# define N 9



bool isSafeInRow(int board[N][N], int row, int n){
    for(int i = 0; i < N; i++){
        if(board[row][i] == n){
            return false;
        }
    }
    return true;
}
bool isSafeInCol(int board[N][N], int col, int n){
    for(int i = 0; i < N; i++){
        if(board[i][col] == n){
            return false;
        }
    }
    return true;
}
bool isSafeInGrid(int board[N][N], int row, int col, int n){

    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i + rowFactor][j + colFactor] == n){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int board[N][N], int row, int col, int n){
    if(isSafeInRow(board, row, n) && isSafeInCol(board, col, n) && isSafeInGrid(board, row, col, n)){
        return true;
    }
    return false;
}

bool findEmptylocation(int board[N][N], int &row, int &col){
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if(board[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}


bool sudokuSolver(int board[N][N]){
    int row, col;
    if(!findEmptylocation(board, row, col)){
        return true;
    }

    for(int i = 1; i <= N; i++){

         if(isSafe(board, row, col, i)){
             board[row][col] = i;
             if(sudokuSolver(board)){
                 return true;
             }
             board[row][col] = 0;
         }
    }

    return false;
}

int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }   

    bool isPossible = sudokuSolver(board);
    
    if(isPossible){
        cout << "true";
    } else {
        cout << "false";
    }
    


    return 0;
}