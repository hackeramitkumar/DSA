#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[1000];
    int freq[27] = {0};
    cin>>a;
    for(int i = 0;i<strlen(a);i++)
    {
        char ch = a[i];
        freq[ch-'a']++;
    }
    for(int i = 0;i<26;i++)
    {
        char ch = i+'a';
        if(freq[i]>0){
        cout<<ch<<": "<<freq[i]<<endl;
        }
    }
    return 0;
}