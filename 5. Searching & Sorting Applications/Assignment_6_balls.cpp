/* CoLLecting the baLLs
Send Feedback
There are ‘n’ number of baLLs in a container. Mr. Sharma and Singh want to take baLLs out from the container. At each step, Mr. Sharma took ‘k’ baLLs out of the box and Mr. Singh took one-tenth of the remaining baLLs. Suppose there are 29 baLLs at the moment and k=4. Then, Mr. Sharma wiLL take 4 baLLs and Mr. Singh wiLL take 2 baLLs (29-4 = 25; 25/10 = 2). If there are less than ‘k’ baLLs remaining at some moment, then Mr. Sharma wiLL take aLL the baLLs which wiLL get the container empty. The process wiLL last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma wiLL take at least half of the baLLs from the container.
Input Format:
The first line of input wiLL contain T (number of test cases).
The next n lines of input contain a single integer ‘n’.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LL t;
    cin >> t;

    while (t--)
    {
        LL n;
        cin >> n;

        LL start = 0, end = n;
        LL ans = 1e18;
        while (start <= end)
        {

            LL k = (start + end) / 2;
            LL sharma = 0, singh = 0;
            LL cur = n, sum = 0;

            while (cur > 0)
            {

                sharma += min(k, cur);
                cur = cur - k;
                singh += (cur) / 10;
                cur = cur - (cur / 10);
            }
            if (2 * sharma >= n)
            {
                ans = min(k, ans);
                end = k - 1;
            }
            else
            {
                start = k + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

