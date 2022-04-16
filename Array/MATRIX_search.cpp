#include<bits/stdc++.h>
using namespace std;
const int Max = 30;

bool binarySearch(int mat[][Max],int n,int m,int k,int x)
{
    int l =0,r=m-1,mid;
    while(l<=r)
    {
        // int count = 0;
        mid = (l+r)/2;
        if(mat[x][mid]==k)
        {             
            return 1;
        }
        else if(mat[x][mid]>k)
        {
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
return 0;    
}

void findRow(int mat[][Max],int n,int m,int k)
{int ans = 0;
    int l = 0,r = n-1,mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(k == mat[mid][0])
        {
            ans = 1;
            break;
        }

         if (k == mat[mid][m - 1]) // checking rightmost
                                // element
        {
            ans = 1;
            break;
        }
        if (k > mat[mid][0] && k < mat[mid][m - 1])
        // this means the element
        // must be within this row
        {
           ans =  binarySearch(mat, n, m, k, mid);
            // we'll apply binary
            // search on this row
            break;
        }
        if (k < mat[mid][0])
            r = mid - 1;
        if (k > mat[mid][m - 1])
            l = mid + 1;
    }
    cout<<ans<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int k;
    cin>>k;
    findRow(arr,n,m,k);
    return 0;
}


