#include <bits/stdc++.h>
using namespace std;

struct Item
{
    double value, weight;
};

bool compare(const Item &a, const Item &b)
{
    double val1 = ((double)a.value) / a.weight;
    double val2 = ((double)b.value) / b.weight;

    return val1 > val2;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    int n;
    double W;
    cin >> n >> W;
    Item items[n];
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    sort(items, items + n, compare);

    double ans = 0;
    for (int i = 0; i < n; i++){
        if(W <= items[i].weight){
            ans += ((double)W/items[i].weight) * items[i].value;
            break;
        }
        ans += items[i].value;
        W -= items[i].weight;
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}