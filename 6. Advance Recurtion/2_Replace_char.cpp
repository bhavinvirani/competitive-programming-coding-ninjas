#include <bits/stdc++.h>
using namespace std;

void replce(char str[], char a, char b)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == a)
    {
        str[0] = b;
    }
    replce(str + 1, a, b);
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        char str[101];
        char A, b;
        cin >> str >> A >> b;

        replce(str, A, b);
        cout << str << endl;
    }
    return 0;
}