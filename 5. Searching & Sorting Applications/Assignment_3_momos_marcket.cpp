// Momos Market
// Send Feedback
// Shreya loves to eat momos. Her mother gives her saved_money to buy vegetables but she manages to save some saved_money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining saved_money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of saved_money left with her at the end of each day.
// Input Format:
// First-line will have an integer ‘n’ denoting the number of shops in the market.
// The next line will have ‘n’ numbers denoting the price of one momo of each shop.
// The next line will have an integer ‘q’ denoting the number of days she will visit the market.
// Next ‘q’ lines will have one integer ‘X’ denoting the saved_money she saved after buying vegetables.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    long long n;
    cin >> n;
    long long shops[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> shops[i];
    }

    long long prefix[n];
    prefix[0] = shops[0];
    for (long long i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + shops[i];
    }

    long long days;
    cin >> days;
    long long saved_money[days];
    for (long long i = 0; i < days; i++)
    {
        cin >> saved_money[i];
    }

    //* Binary aproch

    for (auto x : saved_money)
    {
        long long left = 0;
        long long right = n - 1;
        long long shops = 0;
        long long remain = 0;

        //* all shops
        if (x > prefix[n - 1])
        {
            shops = n;
            remain = x - prefix[n - 1];
        }
        else
        {
            while (left <= right)
            {
                //* if x == mid + 1
                long long mid =  (left + right) / 2;
                if(x == prefix[mid + 1]){
                    shops = mid + 2;
                    remain = 0;
                    break;
                }
                //* x lay between mid and mid + 1;
                if(prefix[mid + 1] >= x && x >= prefix[mid]){
                    shops = mid + 1;
                    remain = x - prefix[mid];
                    break;
                }
                if(x > prefix[mid]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        cout << shops << " " << remain << endl;
    }

    //* Base aproch
    // for (long long i = 0; i < days; i++){
    //     long long remain = 0, momo = 0, money = saved_money[i];
    //     for (long long j = 0; j < n; j++)
    //     {
    //         if(money - shops[j] >= 0){
    //             momo++;
    //             money -= shops[j];
    //             remain = money;
    //         } else {

    //             break;
    //         }
    //     }
    //     cout << momo << " " << remain << endl;
    // }

    

    return 0;
}