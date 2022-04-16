#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int k){
    int l = 0;
    
    int zero_count = 0;
    int max_len = 0;
    int ans_i = 0;
    int ans_j = 0;

    for(int r = 0;r<n;r++){
        if(arr[r] == 0){
            zero_count++;

        }

        while(zero_count > k){
            if(arr[l] == 0)
            zero_count--;
            l++;
        }

        if(max_len < r-l+1)
        {
            ans_i = l;
            ans_j = r;
        }

        max_len = max ( max_len , r - l + 1);
    }

    for(int i = ans_i;i<=ans_j;i++){
        arr[i] = 1;
    }
    return max_len;
}

int longestSubSeg(int a[], int n, int k)
{
    int cnt0 = 0;
    int l = 0;
    int max_len = 0;
 
    // i decides current ending point
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            cnt0++;
 
        // If there are more 0's move
        // left point for current ending
        // point.
        while (cnt0 > k) {
            if (a[l] == 0)
                cnt0--;
            l++;
        }
 
        max_len = max(max_len, i - l + 1);
    }
 
    return max_len;
}
 



//     while(i < n and j < n){
//         if(arr[j] == 1){
//             j++;
//             // max_len++;
//         }else{
//             zero_count++;
//             j++;
//             // max_len++;
//         }
//         while( zero_count > k){
//             if(arr[i] == 0){
//                  zero_count--;

//             }
//         }
//         max_len = j-i+1;

//     }
//     return max_len;
// }
int main(){
    int n;
    int k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k)<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}