#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

bool checkSum(int *arr,int n){
    unordered_set<int> s;
    int pre = 0;
    for(int i = 0;i<n;i++){
        pre += arr[i];
        //check if the sum already present in the cumulative sum array
        if(pre == 0 or s.find(pre) != s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int LengthOfSubbArray(int *arr,int n){

    unordered_map<int,int> m;
    int pre = 0;
    int len = 0;

    for(int i = 0;i<n;i++)
    {
        pre += arr[i];
        if(pre == 0){
            len = max(len,i+1);
        }

        if(m.find(pre) != m.end()){
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
    

    if(checkSum(arr,n)){
        cout<<"Possible \n";
    }else{
        cout<<"Not Possible \n";

    }
return 0;

}