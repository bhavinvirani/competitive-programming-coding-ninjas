#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

string uniqueChar(string str) {
	// Write your code here
    set<char> s;
    string ans = "";
    
    for(auto ch: str){
        if(s.find(ch) == s.end()){
            s.insert(ch);
            ans += ch;
        } 
    }
    
    return ans;
}

int main(){

    return 0; 
}