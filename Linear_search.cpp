#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100] ;
    int n;
    cin>>n;
    int x;
    cin>>x;
    
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];

    }
    int i;
for(i = 0;i<n;i++)
{
    if(arr[i] == x)
    {
        cout<<"found"<<endl;
        break;
    }
   
}
 if(i == n)
    {
        cout<<"not found"<<endl;
    }

    putchar('\n');
    return 0;
}