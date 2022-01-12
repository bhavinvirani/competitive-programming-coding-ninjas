#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void printArray(vector<int> arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve(vector<int> arr, int arri,int opi, vector<int> op)
{   
    //* all index visited / reach to leaf node
    if(arri >= arr.size()){
        int i = op.size();

        if(i != 0){
            printArray(op, i);
        }
    } else {
        solve(arr, arri + 1, opi, op);
        op.push_back(arr[arri]);
        solve(arr, arri + 1, opi, op);
    }
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> op;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, 0, 0, op);
    return 0;
}