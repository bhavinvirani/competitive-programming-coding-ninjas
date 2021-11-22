/* Chef is a cook and he has recently opened a restaurant.

The restaurant is open during N time intervals [L1,R1),[L2,R2),…,[LN,RN). No two of these intervals overlap — formally, for each valid i, j such that i≠j, either Ri<Lj or Rj<Li.

M people (numbered 1 through M) are planning to eat at the restaurant; let's denote the time when the i-th person arrives by Pi. If the restaurant is open at that time, this person does not have to wait, but if it is closed, this person will wait until it is open. Note that if this person arrives at an exact time when the restaurant is closing, they have to wait for the next opening time.

For each person, calculate how long they have to wait (possibly 0 time), or determine that they will wait forever for the restaurant to open.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of the input contains two space-separated integers N and M.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Li and Ri.
M lines follow. For each valid i, the i-th of these lines contains a single integer Pi.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool mySort(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    
    while(t--)
    {
        vector<pair<int, int>> intervals;
        int pairs, queries;
        cin >> pairs >> queries;

        while(pairs--){
            int open, close;
            cin >> open >> close;
            intervals.push_back(make_pair(open, close));  //* 
        }

        sort(intervals.begin(), intervals.end(), mySort);

        while(queries--){
            int x;
            cin >> x;

            //* (start index, last index, what to find) ==>  return iterator of position 
            int position = lower_bound(intervals.begin(), intervals.end(), make_pair(x, 0)) - intervals.begin();
            
            //* if first pair of intervals
            if(position == 0){
                int ans = intervals[0].first - x;
                cout << ans << endl;
            } else {
                int ans = -1;
                //* lays in previous interval
                if(intervals[position - 1].second > x){
                    ans = 0;
                    cout << ans << endl;
                }
                //* lays beetween two interval
                else if(position < intervals.size()){
                    ans = intervals[position].first - x;
                    cout << ans << endl;
                }
                //* out of range (when iterator return last + 1 position)
                else if(position == intervals.size()){
                    cout << ans << endl;
                }

            }
        }



    }
    return 0;
}