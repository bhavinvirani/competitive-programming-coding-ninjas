#include <bits/stdc++.h>
using namespace std;

char crossBord[10][10];

bool isValidHorizontal(int row, int col, string word){
 
	if(10 - col < word.length())
		return false;
 
	for (int i = 0, j = col; i < word.length(); ++i,j++)
	{
		if (crossBord[row][j] != '-' && crossBord[row][j] != word[i]){
			return false;
		}
	}
 
	return true;
}
 
bool isValidVertical(int row, int col, string word){
 
	if(10 - row < word.length())
		return false;
 
	for (int i = row, j = 0; j < word.length(); ++i,j++)
	{
		if (crossBord[i][col] != '-' && crossBord[i][col] != word[j]){
			return false;
		}
	}
 
	return true;
}
 
void setHorizontal(int row, int col, string word, bool state[]){
 
	for (int i = 0, j = col; i < word.size(); ++i, j++)
	{
		if (crossBord[row][j] != '+'){
 
			if(crossBord[row][j] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossBord[row][j] = word[i];
		}
 
	}
}
 
void setVertical(int row, int col, string word, bool state[]){
 
	for (int i = 0, j = row; i < word.size(); ++i, j++)
	{
		if (crossBord[j][col] != '+'){
 
			if(crossBord[j][col] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossBord[j][col] = word[i];
		}
 
	}
}
 
void resetHorizontal(int row, int col, bool state[], int size){
 
	for (int i = 0, j = col; i < size; ++i,j++)
	{
		if(state[i] == true)
			crossBord[row][j] = '-';
	}
	return;
}
 
void resetVertical(int row, int col, bool state[], int size){
 
	for (int i = 0, j = row; i < size; ++i,j++)
	{
		if(state[i] == true)
			crossBord[j][col] = '-';
	}
	return;
}
 
void set_value(bool helper[], int len){
	for(int i=0;i<len;i++){
		helper[i] = false;
	}
}

bool crossWordHelper(string words[], int size, int index)
{
    //* all words are successfully placed in the
    //* EX: in words arry 4 words are present and index 4 accured
    if (index == size)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << crossBord[i][j];
            }
            cout << endl;
        }
        return true;
    }


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // '-' or same char as first of current word
            // set word by word
            if (crossBord[i][j] == '-' || crossBord[i][j] == words[index][0])
            {
                int length = words[index].size();
                bool state[length] = {false};

                set_value(state, length);

                if (isValidHorizontal(i, j, words[index]))
                {
                    setHorizontal(i, j, words[index], state);
                    if (crossWordHelper(words, size, index + 1))
                    {
                        return true;
                    }
                    resetHorizontal(i, j, state, length);
                }

                if (isValidVertical(i, j, words[index]))
                {
                    setVertical(i, j, words[index], state);
                    if (crossWordHelper(words, size, index + 1))
                    {
                        return true;
                    }
                    resetVertical(i, j, state, length);
                }
            }
        }
    }
    return false;
}

void solveCrossWord(string words[], int size)
{

    bool res = crossWordHelper(words, size, 0);
    return;
}

int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);

    string str;
    for (int i = 0; i < 10; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            crossBord[i][j] = str[j];
        }
    }

    char s[200];
    cin >> s;

    string words[7];

    char ch;
    string word = "";
    int a = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {

        if (s[i] == ';')
        {
            words[a++] = word;
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    words[a++] = word;

    solveCrossWord(words, a);

    return 0;
}