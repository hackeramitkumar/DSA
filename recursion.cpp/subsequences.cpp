#include<bits/stdc++.h>
using namespace std;

void subsequences(string s,int i,int n)
{
    
    if(i==n)
    {
        cout<<"'\0'"<<" ";
        return ;
    }



    cout<< s[i]+subsequences(s,i+1,n);
}
int main()
{
    string str;
    cin>>str;
int n = str.length;
    subsequences(str,0,n);
}