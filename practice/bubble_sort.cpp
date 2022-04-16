#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n, int i){
    if(i == n-1){
        return;
    }
    for(int j = 0;j<n-i-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubble_sort(arr,n,i+1);

}

// merge sort

void mergeArray(int *a,int *b,int*c,int s,int e,int mid){
    int i = s;
    int j = mid+1;

    int k = s;


    while(i<=mid and j <= e){

        if(b[i]<=c[j]){
            a[k] = b[i];
            k++;
            i++;
        }
        else{
            a[k] = c[j];
            j++;
            k++;
        }
    }

    while( i<= mid){
        a[k++] = b[i++];
    }
    while(j <= e){
        a[k++] = c[j++];
    }
}

void merge_sort(int *arr, int s , int e){

    if(s >= e){
        return;
    }


// devide
int b[100],c[100];
        int mid = (s+e)/2;


for(int i = s;i<= mid;i++){
    b[i] = arr[i];
}

for(int i = mid+1;i<= e;i++){
    c[i] = arr[i];
}

        merge_sort(b,s,mid);
        merge_sort(c,mid+1 , e);

    // merge
    mergeArray(arr,b,c,s,e,mid);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    


}