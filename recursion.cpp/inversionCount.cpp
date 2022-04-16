#include<bits/stdc++.h>
using namespace std;

int merge(int *a,int s,int e) {
    int mid = (s+e)/2;
    int i =s;
    int j = mid+1;
    int k = s;

    int temp[100000];
     int cnt = 0; //cross inversion

     while(i<=mid and j <= e){
if(a[i] <= a[j]){
         temp[k] = a[i];
         k++;
         i++;
     }else{
         temp[k++] = a[j++];
         cnt += mid-i+1;
     }
}

     //fill the array if some elements are left in one of the arrays
     while(i <= mid){
         temp[k++] = a[i++];
     }
     while(j <= e){
         temp[k++] = a[j++];
     }
     //copy all the elements back to arr a
     for(int i = s;i<=e;i++)
     {
         a[i] = temp[i];
     }
     return cnt;
}

int inversionCount(int arr[],int s,int e){
    //base case
    if(s>=e)
    return 0;

    //merge sort
    int mid = (s+e)/2;
    int x = inversionCount(arr,s,mid);
    int y = inversionCount(arr,mid+1,e);
    int z = merge(arr,s,e); // cross inversion

    return x+y+z;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<inversionCount(arr,0,n-1);
}