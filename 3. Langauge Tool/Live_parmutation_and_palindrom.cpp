#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)i + 97;  // typecast to char
}

void printPlindromicString(string s){

    map<char, vector<int>> indexes;      //* store index of each character in vector

    for(int i = 0; i < s.length(); i++){
        indexes[s[i]].push_back(i);      //* maintains indexes of all characters in vector
    }

    int odd_freq_count = 0;
    for(int i = 0; i < 26; i++){
        if((indexes[getChar(i)].size() % 2) == 1){     //* check with character's vector size
            odd_freq_count++;
        }
    }
    //* if more than one odd frequency count then palindrome can not possible
    if(odd_freq_count > 1){
        cout << "-1";
        return;
    }

    int ans[s.length()]; //* string sized array 
    int start = 0;
    int end = s.size()-1;

    for(int i = 0; i < 26; i++) {
        char currentChar = getChar(i);

        //* run till size of character's vector
        for(int j = 0; j < indexes[currentChar].size(); j+=2){

            //* whene single index is remaining in vector
            //* put it into middle of answetr array
            if((indexes[currentChar].size() - j) == 1){
                ans[s.length()/2] = indexes[currentChar][j];
                continue;
            }
            
            ans[start++] = indexes[currentChar][j];
            ans[end--] = indexes[currentChar][j+1];
        }
    }


    //* printing answer 
    for(int i = 0; i < s.length(); i++){
        cout << ans[i] + 1 << " ";
    }

    return;

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        printPlindromicString(s);
        cout << endl;
        
    }
    return 0;
}