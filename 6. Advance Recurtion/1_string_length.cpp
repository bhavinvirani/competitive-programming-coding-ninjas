#include <bits/stdc++.h>
using namespace std;

int length(char str[]){
    if(str[0] == '\0'){
        return 0;
    }
    return 1 + length(str + 1);
}

void removeX(char str[]){
    if(str[0] == '\0'){
        return;
    }
    if(str[0] != 'x'){
        removeX(str + 1);
    } else {
        int i = 1;
        for(; str[i] != '\0'; i++){
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i];
        removeX(str); //* check consucative accurance of 'x'
    }
}


int main() {
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    char str[100];
    cin >> str;

    // int l = length(str);
    // cout << l << endl;

    removeX(str);
    cout << str << endl;

    

    return 0;
}