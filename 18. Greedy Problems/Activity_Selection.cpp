#include <bits/stdc++.h>
using namespace std;
bool sortBySec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    /*
    if true not swap,
    if false swap whole pair
    */
    return (a.second < b.second);
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        vect.push_back(make_pair(s, e));
    }

    //* sort by second element (Finish time)
    sort(vect.begin(), vect.end(), sortBySec);
    // for(auto pair : vect){
    //     cout << pair.first << " " << pair.second << endl;
    // }

    //* Activities selection
    int i = 0;
    int count = 1;

    for(int j = 1; j < vect.size(); j++){
        if(vect[j].first >= vect[i].second){
            count++;
            i = j;
        }
    }
    cout << count;
    return 0;
}