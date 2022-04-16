#include<bits/stdc++.h>
using namespace std;

int solve(int *arr1, int *arr2, int n,int m,int *ans){
    int i = n-1;
    int j = m-1;
    int len = 0;
    int carry = 0;
    while(i >= 0 and j >= 0){
        int curr = arr1[i] + arr2[j] + carry;
        ans[len] = curr%10;
        carry = curr/10;
        i--;
        j--;
        len++;
    }

    while(i>= 0){
        int curr = arr1[i] + carry;
        ans[len] = curr%10;
        carry = curr/10;
        i--;
        len++;
    }
    while(j>= 0){
        int curr = arr2[i] + carry;
        ans[len] = curr%10;
        carry = curr/10;
        j--;
        len++;
    }

    while(carry > 0){
        ans[len] = carry%10;
        carry = carry/10;
        len++;
    }
    return len;
}

int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i = 0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[m];
    for(int i = 0;i<m;i++){
        cin>>arr2[i];
    }


    int ans[100] = {0};
    int len = solve(arr1,arr2,n,m,ans);
    for(int i = len-1;i>=0;i--){
        cout<<ans[i]<<", ";
    }
    cout<<"END"<<endl;








}