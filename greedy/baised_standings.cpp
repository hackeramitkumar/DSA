#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int arr[100000] = {0};

    while(t--){
        int n,rank;
        string name;
        cin>>n;
        for(int i = 0; i<n;i++){
            cin>>name>>rank;
            arr[rank]++;
        }

        //greedy approach - assign the team nearest rank possible
        int actual_rank = 1;
        int sum = 0;

        for(int i = 1;i<=n;i++){
            while(arr[i]){
                 sum += abs(actual_rank - i);
                 arr[i]--;
                 actual_rank++;
            }


        }
        cout<<sum<<endl;

    }
    return 0;
}