#include<bits/stdc++.h>
using namespace std;
int Count(int arr[][30],int n,int m)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<m;j++)
        {
            for(int k = 0;k<j;k++)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int m,n;
    int arr[30][30];
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }


    cout<<Count(arr,m,n)<<endl;

    return 0;

}