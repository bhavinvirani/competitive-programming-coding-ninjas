#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> input, int n) {
    int output[n] = {0};
    output[0] = 1;

    for(int i = 1; i < n; i++) {
        output[i] = 1;
        int x = i - 1;

        while(x >= 0){

            //* previous x number is larger then current number can not be add
            if(input[x] > input[i] ){
                x--;
                continue;
            }
            //? LIC from x to i
            //* if x is amaller then we can add i next to x so, op[x] + 1;
            //* possibleAns = output[x] + 1; 
            output[i] = max(output[i], output[x] + 1);
            x--;
        }
    }

    int best = 0;
    for(int i = 0; i < n; i++){
        if(best < input[i]){
            best = output[i];
        }
    }
    return best;
}


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> input;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;;
        input.push_back(temp);
    }

    int ans = LIS(input, n);
    cout << ans << endl;
    return 0;
}