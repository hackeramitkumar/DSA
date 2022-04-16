#include<bits/stdc++.h>
using namespace std;


int main()
{
//1st way
    string s = "hello";

    //second way
    string s2 = s;

    //third way
    string s3(s);

    //using character array
     /*   char a[100];
    cin>>a;

    string s4(a);
    */

    //update the string
    s = "new value can be given";

    //concat
    string x = "Amit";
    string y = "rajpoot";

     //x = x+y; this will  njot have a space between two strings
     x = x + " " +y;

     //Find the particular word in a string it will return us the ndex of that word
    s = "new value can be given";
// i want to search can in string s

string word = "can";
     cout<<s.find(word)<<endl;
     int index = s.find(word);

     //I want to delete the word can
     s.erase(index , word.length()+1);
     cout<<s<<endl;

}