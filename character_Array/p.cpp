#include<bits/stdc++.h>
using namespace std;

void readLines(char arr[],char delimiter)
{
    int i = 0;
    char ch = cin.get();
    while(ch!= delimiter)
    {
        
        arr[i] = ch;
        i++;
        ch = cin.get();
        if(ch>='A'&&ch<='Z')
        {
            arr[i]='\n';
            i++;
        }
    }
    arr[i] = '\0';
}

int main()
{
    char a[2000];
  readLines(a,'\n');

cout<<a<<endl;
    return 0;
}