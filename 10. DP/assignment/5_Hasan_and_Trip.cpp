/* Hasan and Trip
Send Feedback
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line will contain T(number of test case).
First line of each test case will contain an integer N
Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)
Output format:
For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get.
Note: If answer is 2 print 2.000000
Constraints:
1 <= T <= 50
1 <= N <= 500
0 <= Xi, Yi, Fi <= 100,000
Sample Input
1
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445 */

#include <bits/stdc++.h>
using namespace std;

struct city{
    int x, y;
    int happiness;
};

double distance(city a, city b){
    //* method to find distance between two elements 
	double ans = 0;
	long long X = (long long)pow(a.x-b.x, 2);
	long long Y = (long long)pow(a.y-b.y, 2);
	
	ans = (double)sqrt(X+Y);
	return ans;
}

double solve(vector<city> cities, int n){
    vector<double> dp(n, 0);
    //* whene only 1 city the only possiblity
    dp[0] = cities[0].happiness;

    for (int i = 1; i < n; i++)
    {
        double tmp = -1e9;
        
        for (int j = 0; j < i; j++)
		{   
            //* find max from previous visted cities
			tmp = max(tmp, dp[j] + cities[i].happiness - distance(cities[i], cities[j]));
		}
        //* add maximum happiness for that city
        dp[i] = tmp;
    }
    return dp[n-1];
    

}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<city> cities(n);
        
        for(int i = 0; i < n; i++){
            cin >> cities[i].x >> cities[i].y >> cities[i].happiness;
        }

        double ans = solve(cities, n);

        cout << fixed << setprecision(6) << ans << endl;

        
    }
    return 0;
}
