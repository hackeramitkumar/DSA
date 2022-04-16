#include<bits/stdc++.h>
using namespace std;

int out[100];
int j= 0;
void AllOccurance(int *arr,int n,int i,int key)
{
    // base case
   if(i == n)
   return ;

   if(arr[i] == key){
   out[j] = i;
   j++;
   }

   AllOccurance(arr,n,i+1,key);
}
int main()
{

        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int key;
        cin>>key;
        AllOccurance(arr,n,0,key);
        cout<<"indexes are: "<<endl;
        for(int i = 0;i<j;i++)
        {
            cout<<out[i]<<" ";
        }
        cout<<endl;
    
    return 0;
}
