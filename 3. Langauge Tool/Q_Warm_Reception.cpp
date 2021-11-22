#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.

// She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.

// Input Format :
// First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.

// 5
// 900 1000 1100 1030 1600
// 1900 1300 1130 1130 1800


struct detail{
    int time;
    bool status; //* in or out
};

bool my_sort(detail a, detail b){
    return (a.time < b.time);
}

int main() {

	// Write your code here
	int n;
    cin >> n;
    vector<detail> people;
    
// Arrival    
    for(int i = 0; i < n; i++) {
        int temp_time;
        cin >> temp_time;

        detail temp;
        temp.time = temp_time;
        temp.status = 1;
        people.push_back(temp);
    }

// departure

    for(int i = 0; i < n; i++) {
        int temp_time;
        cin >> temp_time;

        detail temp;
        temp.time = temp_time;
        temp.status = 0;
        people.push_back(temp);
    }

    sort(people.begin(), people.end(), my_sort);

    int ans = 0, count = 0;
    for(int i = 0; i < people.size(); i++) {
        if(people.at(i).status == 1) {
            count++;
        } else {
            count--;
        }
        ans = max(ans, count);
    }
    cout << ans;
    
      

    return 0;
}