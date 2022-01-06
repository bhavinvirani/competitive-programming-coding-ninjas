//? Longest Common Subsequence
/* pick at any position from string array  */


#include <bits/stdc++.h>
using namespace std;

int lcs(char * s1, char * s2){
    //* whene any string became empty
    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }

    //* first characters matched
    if(s1[0] == s2[0]){
        return 1 + lcs(s1+1, s2+1);
    } else {
        //* keep first character of s1 and skip first character of s2
        int option1 = lcs(s1, s2 + 1);
        //* keep first character of s2 and skip first character of s1
        int option2 = lcs(s1 + 1, s2);
        return max(option1, option2);
    }
}

int lcs_memo_helper(char * s1, char * s2, int m, int n, vector<vector<int>> memo){
    //* whene any string became empty
    if(m == 0 || n == 0){
        return 0;
    }
    if(memo[m][n] > -1){
        return memo[m][n];
    }

    int ans;
    //* first characters matched
    if(s1[0] == s2[0]){
        ans =  1 + lcs_memo_helper(s1+1, s2+1, m - 1, n - 1, memo);
    } else {
        //* keep first character of s1 and skip first character of s2
        int option1 = lcs_memo_helper(s1, s2 + 1, m, n - 1, memo);
        //* keep first character of s2 and skip first character of s1
        int option2 = lcs_memo_helper(s1 + 1, s2, m - 1, n, memo);
        ans =  max(option1, option2);
    }
    memo[m][n] = ans;
    return ans;
}
int lcs_memo(char *s1, char *s2){
    int m = strlen(s1);
    int n = strlen(s2);
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

    int ans = lcs_memo_helper(s1, s2, m, n, memo);
    return ans;
}

int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    char a[100];
    char b[100];

    cin >> a >> b;
    // cout << lcs(a, b) << endl;
    cout << lcs_memo(a, b) << endl;

    return 0;
}