#include<bits/stdc++.h>
using namespace std;
void longestKUnique(char a[],int k)
{
    int i=0;
    int freq[26] = {0};
    int cnt = 0;
    int len = -1;
    for(int j = 0; a[j]!='\0';j++)
    {
        freq[a[j]-'a']++;
        if(freq[a[j]-'a'] == 1)
        {
            cnt++;
        }
        while(cnt>k)
        {
            freq[a[i]-'a']--;
            if(freq[a[i]-'a'] == 0)
            {
                cnt--;
            }
            i++;
        }
        if(cnt == k)
        {
            len = max(len,j-i+1);
        }
    }
    cout<<"Length of the largest substring having "<<k<<"unique character: "<<len<<endl;

}

int main()
{
    char a[1000];
    cin>>a;
    int k;
    cin>>k;
    longestKUnique(a,k);
    return 0;

}