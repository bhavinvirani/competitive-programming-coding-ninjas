#include<bits/stdc++.h>
using namespace std;


// Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int a = 0, s = 0, p = 0;
    for(auto ch: str){
        switch(ch){
            case 'a':
                a++;
                break;
            case 's':
                s++;
                break;
            case 'p':
                p++;
                break;
        }
    }
    cout << a <<" "<< s <<" "<< p;
    
	return 0;
}
