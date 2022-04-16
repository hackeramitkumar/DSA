#include<bits/stdc++.h>
using namespace std;

void sumItUp(int *arr,int *out,int n,int target,int i,int j)
{
    
    if(i == n){
        if(target == 0){
        int k = 0;
        while(out[k]!=0)
        {
            cout<<out[k]<<" ";
            k++;
        }
        putchar('\n');
        }
        return;
    }
    
       if(target-arr[i] >= 0)
       {
        //    //ignore 
        // sumItUp(arr,out,n,target,i+1,j);

        // //    take
        out[j] = arr[i];
        sumItUp(arr,out,n,target-arr[i],i+1,j+1);

       }
        out[j] = 0;
        sumItUp(arr,out,n,target,i+1,j);
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int out[100] = {0};

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cin>>target;
     sumItUp(arr,out,n,target,0,0);
}