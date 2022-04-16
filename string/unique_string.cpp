#include<bits/stdc++.h>
using namespace std;


int solve(vector<string> v, int i, string ans){
    if(i == v.size()){
        int freq[26] = {0};
        for(int i = 0;ans[i] != '\0';i++){
            int idx = ans[i] - 'a';
            if(freq[idx] > 0){
                return 0;
            }
            freq[idx]++;
        }
        return ans.length();

    }

    int op1,op2;
    op1 = op2 = INT_MIN;

    if(ans.length() + v[i].length() <= 26){
        op1 = solve(v,i+1,ans+v[i]);
    }
    op2 = solve(v,i+1,ans);

    return max(op1,op2);

}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    // int freq[26] = {0};
    string ans = "";
    cout<<solve(v,0,ans)<<endl;

    

}


// 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