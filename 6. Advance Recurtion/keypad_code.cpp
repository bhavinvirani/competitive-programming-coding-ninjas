#include <bits/stdc++.h>
using namespace std;

vector<string> keypad(int num)
{
    if (num <= 1)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    int curNum = num % 10;
    int smallNum = num / 10;

    vector<string> ans; //* make new vector to contain char from all number
    vector<string> smallAns;

    smallAns = keypad(smallNum); //* give strig combination of (n / 10)
    string input;
    switch (curNum)
    {
    case 2:
        input = "abc";
        break;
    case 3:
        input = "def";
        break;
    case 4:
        input = "ghi";
        break;
    case 5:
        input = "jkl";
        break;
    case 6:
        input = "mno";
        break;
    case 7:
        input = "pqrs";
        break;
    case 8:
        input = "tuv";
        break;
    case 9:
        input = "wxyz";
        break;
    }

    for (int i = 0; i < int(input.length()); i++)
    {
        for (int j = 0; j < int(smallAns.size()); j++)
        {
            ans.push_back(smallAns[j] + input[i]);
        }
    }
    return ans;
}

void printKeypad(int num, string output)
{
    if (num <= 0)
    {
        cout << output << endl;
        return;
    }
    int curNum = num % 10;
    int smallNum = num / 10;
    string input;
    switch (curNum)
    {
    case 2:
        input = "abc";
        break;
    case 3:
        input = "def";
        break;
    case 4:
        input = "ghi";
        break;
    case 5:
        input = "jkl";
        break;
    case 6:
        input = "mno";
        break;
    case 7:
        input = "pqrs";
        break;
    case 8:
        input = "tuv";
        break;
    case 9:
        input = "wxyz";
        break;
    }

    printKeypad(smallNum, input[0] + output);
    printKeypad(smallNum, input[1] + output);
    printKeypad(smallNum, input[2] + output);
    if (curNum == 7 || curNum == 9)
    {
        printKeypad(smallNum, input[3] + output);
    }
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
        // vector<string> ans = keypad(n);

        // for (int i = 0; i < int(ans.size()); i++)
        // {
        //     cout << ans[i] << endl;
        // }

        printKeypad(n, "");
    }
    return 0;
}