#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){

    //? aproch 1
    // set<int> s;
    // vector<int> ans;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //* find number in set
    //     if(s.find(arr[i]) == s.end()){   //* if not found then add it to ans and set
    //         s.insert(arr[i]);
    //         ans.push_back(arr[i]);
    //     }
    // }
    // return ans;

    //? aproch 2

    vector<int> v;
    sort(arr.begin(), arr.end());   //* sort the whole array
    v.push_back(arr[0]);            //* insert the first element

    //* compare with previous element if not matched then add to ans
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i - 1]){
            v.push_back(arr[i]);
        }
    }
}

int main() {

    vector<int> v;
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter Elements";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> ans = removeDuplicates(v);
    for(auto el: ans){
        cout << el << " ";
    }

    return 0;
}