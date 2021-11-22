#include<bits/stdc++.h>
using namespace std;


// In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.

// Input Format:
// First line will have a single integer ‘n’, denoting the number of students in the class.
// Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.


struct student{
    string name;
    int no;
    int total = 0;
};

bool mycompare(student a, student b){
    if(a.total != b.total){         
        return (a.total > b.total);  //* total marks in descending order ( l_total > r_total )
    } else {
        return (a.no < b.no);        //* roll in ascending order ( l_rol < r_roll )
    }
}


int main()
{
    
    int n;
    cin >> n;
    vector<student> st;
    
    for(int i = 0; i < n; i++){
        string temp_name;
        int sub1, sub2, sub3, temp_total = 0;
        cin >> temp_name >> sub1 >> sub2 >> sub3;
        temp_total = sub1+sub2+sub3;
        
        student temp;
        temp.name = temp_name;
        temp.total = temp_total;
        temp.no = i+1;
        
        st.push_back(temp);
        
    }
	
    sort(st.begin(), st.end(), mycompare);
   
    
    for(int i = 0; i < n; i++){
        cout << i+1 << " " << st.at(i).name << endl;
    }
    return 0;
}
