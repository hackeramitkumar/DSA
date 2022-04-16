#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(char a[])
{
    int i = 0,j = 1;
    int l = strlen(a);
    while(j<l)
    {
        if(a[i]==a[j])
        {
            j++;
        }else{
            i++;

            a[i] = a[j];
            // j++;
        }
    }
    a[i+1] = {'\0'};

}

int main()
{
    int n;
    cin>>n;
    cin.get();
    char a[1000];
    for(int i = 0;i<n;i++)
    {
        cin>>a;
        removeDuplicate(a);
        cout<<a<<endl;
    }
    return 0;

}