#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char nonRepetingStringChar(string str){
    map<char, int> feq;

    //* count frequency of string's characters
    for(int i=0; i<str.length(); i++){
        feq[str[i]]++; 
    }

    //* if string frequency is 1 then return
    for(auto ch: str){
        if(feq[ch] == 1){
            return ch;
        }
    }
    return str[0];
}

int main() {
    string str;
    cin >> str;
    char ans = nonRepetingStringChar(str);
    cout << ans;

    return 0;
}