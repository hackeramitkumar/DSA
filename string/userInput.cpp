#include<bits/stdc++.h>
using namespace std;

int main()
{
    // string s;
    // getline(cin,s); //by defualt delemiter is '\n'
    // getline(cin,s, '$');
    // cout<<s<<endl;

    string s2 = "world";
    string s1 = "Hello";

/*    if(s1<s2)
    {
        cout<<"S2 is laxixografically greater ";
    }else{
        cout<<"S1 is laxixografically greater ";
    }
    putchar('\n');


*/
    //We have a compare function
    cout<<s1.compare(s2)<<endl; // if(s1 == s2) --> 0 , >0 , <0

}