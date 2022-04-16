#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno ? true : false;
    }
};

class HashFn
{
public:
    // this must be in this class
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};

int main()
{
    unordered_map<Student, int, HashFn> student_map;
    Student s1("amit", "kumar", "010");
    Student s2("rohit", "sharma", "015");
    Student s3("Rahul", "savita", "023");
    Student s5("Rahul", "savita", "029");

    Student s4("Rahul", "rajput", "021");

    // Add students marks to hash table
    student_map[s1] = 110;
    student_map[s2] = 190;
    student_map[s3] = 150;
    student_map[s4] = 10;
    student_map[s5] = 100;
    student_map[s3] = 150;



    // iterator iterate ove the whole hash table
    for (auto s : student_map)
    {
        cout << s.first.firstname << " " << s.first.lastname <<" "<< s.first.rollno << " "
             << "Marks :" << s.second << endl;
    }
    return 0;
}
