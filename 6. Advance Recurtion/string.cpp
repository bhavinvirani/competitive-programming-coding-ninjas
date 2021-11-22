#include <iostream>
using namespace std;

int main() {

	string* sp = new string;  //* dynamically allocated memory
	*sp = "def";
	cout << sp << endl;
	cout << *sp << endl;

	string s = "abc";
	//getline(cin, s);
	cout << s << endl;
	
	s = "defdef";
	cout << s[0] << endl;
	s[0] = 'a';
	string s1;
	s1 = "def";

	string s2 = s + s1;  	//* concate
	cout << s2 << endl;
	s += s1;

	cout << s1 << endl;
	cout << s << endl;

	cout << s.size() << endl;
	cout << s.substr(3) << endl;	  //* all after index 3
	cout << s.substr(3, 4) << endl;	  //* 4 after index 3(3 included)

	cout << s.find("def") << endl;    //* from which index to start





}
