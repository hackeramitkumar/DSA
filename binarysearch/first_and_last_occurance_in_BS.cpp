#include<bits/stdc++.h>
using namespace std;

int first_occurance(int a[],int n,int key)
{
    int s = 0 , e = n-1;
int ans = -1;
    while(s<=e){
        int mid = e - (s+e)/2;

        if(a[mid] == key)
        {
            //here we have to do two things
            ans = mid;
            e = mid -1;
        }else if(a[mid]>key)
        {
            return e = mid-1;
        }else{
            s = mid+1;
        }
        
    }
    return ans;
}

int last_occurance(int a[],int n,int key)
{
    int s = 0 , e = n-1;
int ans = -1;
    while(s<=e){
        int mid = e - (s+e)/2;

        if(a[mid] == key)
        {
            //here we have to do two things
            ans = mid;
            s = mid + 1;
        }else if(a[mid]>key)
        {
            return e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"first occurance of the "<<key<<"is at the index : "<<first_occurance(arr,n,key)<<endl;
    cout<<"last occurance of the "<<key<<"is at the index : "<<last_occurance(arr,n,key)<<endl;
    return 0;
}