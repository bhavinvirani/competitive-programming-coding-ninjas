#include <bits/stdc++.h>
using namespace std;


int main() {

    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int length;
    cin >> length;
    string s1,s2;
    cin >> s1 >> s2;
    int count = 0;

    for(int i = 0; i < length; i++){
        if(s1[i] != s2[i]) {
            if(s1[i] != s1[i + 1] && s1[i + 1] != s2[i + 1]){
                swap(s1[i],s1[i + 1]);
                count++;
                i++;
            } else{
                if(s1[i] == '1'){
                    s1[i] == '0';
                } else {
                    s1[i] = '0';
                }
                count++;
            }
            
        } 
    }
    cout << count;



    return 0;
}