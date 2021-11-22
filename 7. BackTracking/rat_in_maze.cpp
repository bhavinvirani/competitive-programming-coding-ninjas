#include <bits/stdc++.h>
using namespace std;

int maze[20][20] = {0};
int path[20][20] = {0};

bool canRight(int n, int row, int col)
{
    if (maze[row][col + 1] == 1 && path[row][col + 1] == 0 && (col + 1) != n)
    {
        return true;
    }
    return false;
}
bool canDown(int n, int row, int col)
{
    if (maze[row + 1][col] == 1 && path[row + 1][col] == 0 && (row + 1) != n)
    {
        return true;
    }
    return false;
}
bool canLeft(int n, int row, int col)
{
    if (maze[row][col - 1] == 1 && path[row][col - 1] == 0 && (col - 1) != -1)
    {
        return true;
    }
    return false;
}
bool canUp(int n, int row, int col)
{
    if (maze[row - 1][col] == 1 && path[row - 1][col] == 0 && (row - 1) != -1)
    {
        return true;
    }
    return false;
}

void printPath(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (path[i][j] == 1)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
    }
    cout << endl;
    return;
}

void find_path(int n, int row, int col)
{
    if (row == n -1 && col == n - 1)
    {   
        path[row][col] = 1;
        printPath(n);
        path[row][col] = 0;

        return;
    }

    if (maze[row][col] == 1 && canRight(n, row, col))
    {
        path[row][col] = 1;
        find_path(n, row, col + 1);
        path[row][col] = 0;
    }
    if (maze[row][col] == 1 && canDown(n, row, col))
    {
        path[row][col] = 1;
        find_path(n, row + 1, col);
        path[row][col] = 0;
    }
    if (maze[row][col] == 1 && canLeft(n, row, col))
    {
        path[row][col] = 1;
        find_path(n, row, col - 1);
        path[row][col] = 0;
    }
    if (maze[row][col] == 1 && canUp(n, row, col))
    {
        path[row][col] = 1;
        find_path(n, row - 1, col);
        path[row][col] = 0;
    }

    return;
}

void maze_in_rate(int n)
{
    memset(path, 0, 20 * 20 * sizeof(int));
    find_path(n, 0, 0);

    return;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    maze_in_rate(n);

    return 0;
}