#include<bits/stdc++.h>
using namespace std;


bool search(int arr[][100],int n,int m,int key)
{
    int  i = 0;int j = m-1;
    bool isKEyPresent = true;
    while(i<n and j>=0)
    {
        if(arr[i][j] == key)
        {
            isKEyPresent = true;
            break;
        }else if(arr[i][j]>key)
        {
            j--;
        }else
        {
            i++;
        }
    }
    return isKEyPresent;
}
int main()
{
    int m,n;
    int arr[100][100];
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int k;
    cin>>k;
    cout<<search(arr,m,n,k)<<endl;

    return 0;

}