#include <bits/stdc++.h>
using namespace std;


int subs(string str, string ans[]){
    if(str.empty()){
        ans[0] = "";
        return 1;
    }

    string smallstring = str.substr(1);
    int smallOutputSize = subs(smallstring, ans);

    for (int i = 0; i < smallOutputSize; i++)
    {
        ans[i + smallOutputSize] = str[0] + ans[i];  
    }
    
    return 2 * smallOutputSize;

}

void subPrint(string str, string output){
    if(str.empty()){
        cout << output << " ";
        return;
    }
    string smallstring = str.substr(1);
    subPrint(smallstring, output);
    subPrint(smallstring, str.front() + output);
}


int main() {

    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    string str;
    cin >> str;

    string* ans = new string[1000];
    
    // int count = subs(str, ans);

    // for(int i = 0; i < count; i++) {
    //     cout << ans[i] << endl;
    // }

    subPrint(str, "");

    return 0;
}



