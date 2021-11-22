#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
// Note: We don't have to mention names whose frequency is 1.

int main() {
    // Write your code here
	string str;
    getline(cin, str);
    
    map<string, int> feq;
    int count = 0;
   	
    str[str.length()] = ' ';
    str[str.length() + 1] = '\0';
    
  	string word = "";
    for(int i = 0; i <= str.length() ; i++){
  		if(str[i] == ' ')  	{        
            feq[word]++;
            word = "";
        } else {
            word += str[i];
        }
    }
    
    for(auto pair: feq){
        if(pair.second >= 2){
            cout << pair.first << " " << pair.second << endl;
            count++;
        }
    }
    if(!count){
        cout << "-1";
    }
    
    
    
    
    
}