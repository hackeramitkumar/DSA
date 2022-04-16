#include<bits/stdc++.h>
using namespace std;

int first_occurance(int *arr,int n, int key){

int s = 0;
int e = n-1;
int ans = -1;
while(s<=e){
    int mid = (s+e) / 2;
    if(arr[mid] == key){
        e = mid-1;
        ans = mid;
    }else if(arr[mid] > key){
        e = mid-1;
    }else{
        s = mid + 1;
    }
}
return ans;

}



int last_occurance(int *arr,int n, int key){
    
int s = 0;
int e = n-1;
int ans = -1;
while(s<=e){
    int mid = (s+e) / 2;
    if(arr[mid] == key){
        s = mid + 1;
        ans = mid;
    }else if(arr[mid] > key){
        e = mid-1;
    }else{
        s = mid + 1;
    }
}
return ans;

}



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int key ;
    cin>>key;
    cout<<first_occurance(arr,n,key)<<endl;
    cout<<last_occurance(arr,n,key)<<endl;

}