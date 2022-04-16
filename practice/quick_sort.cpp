#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int s, int e){
    int i = s-1;

    for(int j = s;j<e;j++){
        if(a[j] <= a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
    
}

void quick_sort(int *a,int s, int e){
    if(s>=e){
        return;
    }

    int idx = partition(a,s,e);
    quick_sort(a,s,idx-1);
    quick_sort(a,idx+1,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    quick_sort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    


}