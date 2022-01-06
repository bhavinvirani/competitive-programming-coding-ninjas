#include <bits/stdc++.h>
using namespace std;

int lcs(char * s1, char * s2){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }

        }
    }

    // for(auto row : dp){
    //     for(auto i : row){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    // string str = "";
    // for(int i = n1; i >= 0; i--){
    //     for(int j = n2; j >= 0; j--){
    //         if(dp[i][j] == dp[i-1][j-1] + 1){
    //             str = str + s2[j];
    //             i--;
    //         }
    //     }
    // }
    // cout << str << endl;
    return dp[n1][n2];
}


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    
    char s1[100];
    char s2[100];
    cin >> s1 >> s2;
    cout << lcs(s1,s2) << endl;
    return 0;
}