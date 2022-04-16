#include<bits/stdc++.h>
using namespace std;

bool search(int *arr,int n, int key){

int s = 0;
int e = n-1;
while(s<=e){
    int mid = (s+e) / 2;
    if(key <= arr[s]){
        if(arr[mid] < key){
            s = mid+1;
        }else if(arr[mid] > key){
            e = mid-1;
        }else{
            return true;
        }
    }else{
        if(arr[mid] < key){
            s = mid + 1;
        }else if(arr[mid] > key ){
            e = mid - 1;
        }else{
            return true;
        }

    }
}
    return false;


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
    cout<<search(arr,n,key)<<endl;

}