#include<bits/stdc++.h>
using namespace std;
int lastOccurance(int *a,int n,int i,int key)
{
    //base case
    if(i == n)
    return -1;

    if(a[i] == key)
    {
        int bi = lastOccurance(a,n,i+1,key);
        if(bi != -1){
        return bi;
        }
        else{
            return i;
        }
    }

    int j= lastOccurance(a,n,i+1,key);

    return j;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;
    cin>>key;
    cout<<lastOccurance(arr,n,0,key)<<endl;
}