#include<bits/stdc++.h>
using namespace std;

/*
int waterStore(int arr[],int n)
{
    int res = 0;
    for(int i = 1;i<n-1;i++)
    {
        int left = arr[i];
        for(int j = 0;j<i;j++)
        {
            left = max(left,arr[j]);
        }

        int right = arr[i];
        for(int j = i+1;j<n;j++)
        {
            right = max(right,arr[j]);
        }
        res = res+ min(left,right)-arr[i];
    }
    return res;

}
*/
//optimize two pointer approach
int waterStore_optimize(int arr[],int n){
    int left_max = 0;
    int right_max = 0;
    int lo = 0;
    int ro = n-1;
    int water = 0;
    while(lo<=ro){
        if(arr[lo]<arr[ro]){
            if(arr[lo]>left_max){
                left_max = arr[lo];
            }else{
                water += (left_max-arr[lo]);
            }
            lo++;
        }else{
            if(arr[ro]>right_max){
                right_max = arr[ro];
            }else{
                water += (right_max - arr[ro]);
            }
            ro--;
        }
    }
    return water;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
   int water_opt = waterStore_optimize(arr,n);

   cout<<water_opt<<endl;
   return 0;

}