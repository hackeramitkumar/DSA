#include<bits/stdc++.h>
using namespace std;

int findLargestSeq(int *arr,int n){
    unordered_map<int,int> m;
    for(int i = 0;i<n;i++){
        int no = arr[i];

// case -> 1 : new streak
        if(m.count(no-1) == 0 and m.count(no+1) == 0){
            m[no] = 1;

            // case : add both left and right streak
        }else if(m.count(no-1) and m.count(no+1)){
            int len1 = m[no-1];
            int len2 = m[no+1];
            int streak = len1+len2+1;
            m[no-len1] = streak;
            m[no+len2] = streak;

// right expansion
        }else if(m.count(no-1) and !m.count(no+1)){
            int len = m[no-1];
            m[no-len] = len+1;
            m[no] = len+1;
        }else{
            int len = m[no+1];
            m[no+len] = len+1;
            m[no] = len+1;
        }
    }
    int largest = 0;
    for(auto p: m){
        largest = max(p.second,largest);
    }
    return largest;
}
int findLargetSeq_SET(int *arr,int n){
    unordered_set<int> s;
    int max_streak = 0;
    for(int i = 0;i<n;i++){
        s.insert(arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(s.find(arr[i]-1)== s.end()){
            int next_no = arr[i] + 1;
            int streak_len = 1;
            while(s.find(next_no) != s.end()){
                next_no += 1;
                streak_len += 1;
            }
            max_streak = max(streak_len,max_streak);
        }
    }
    return max_streak;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i  = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findLargestSeq(arr,n)<<endl;
    return 0;
}