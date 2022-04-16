#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int > > ans;
        
        int n = nums.size();
        long long int total_sets = 1 << n;
        
        
        for(long long int counter = 0;counter < total_sets;counter++){
            for(int j = 0;j < n;j++){
                if(counter & (1<<j) > 0){
                    ans[counter].push_back(nums[j]);
                }
            }
        }
        
        
        return ans;
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Solution s;
    vector<vector<int> > sol = s.subsets(v);
    for(int i = 0;i<sol.size();i++){
        for(auto x: sol[i]){
            cout<<x<<" ";
        }
        cout<<endl;

    }
    return 0;
}