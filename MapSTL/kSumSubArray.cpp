#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

bool checkSum(int *arr,int n,int k){
    unordered_set<int> s;
    int pre = 0;
    for(int i = 0;i<n;i++){
        pre += arr[i];
        //check if the sum already present in the cumulative sum array
        if(pre == k or s.find(pre-k) != s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}


int LengthOfSubbArray(int *arr,int n,int k){

    unordered_map<int,int> m;
    int pre = 0;
    int len = 0;

    for(int i = 0;i<n;i++)
    {
        pre += arr[i];
        if(pre == k){
            len = max(len,i+1);
        }

        if(m.find(pre-k) != m.end()){
            len = max(len,i - m[pre]);
        }else{
            m[pre] = i;
        }
    }
    return len;

}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];

    }
    int k;
    cin>>k;
    

    if(checkSum(arr,n,k)){
        cout<<"Possible \n";
    }else{
        cout<<"Not Possible \n";

    }
return 0;

}