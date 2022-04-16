#include<bits/stdc++.h>
using namespace std;




int LCS(string s1,string s2,string s3,int i,int j, int k ,int dp[100][100][100]){
    if( i == s1.length() || j == s2.length() || k == s3.length()){
        return 0;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    if(s1[i] == s2[j] and s2[j] == s3[k]){
            dp[i][j][k] = 1 + LCS(s1,s2,s3,i+1,j+1,k+1,dp);
            return dp[i][j][k];
        }else{
            dp[i][j][k] = max(LCS(s1,s2,s3,i+1,j,k,dp),max(LCS(s1,s2,s3,i,j+1,k,dp), LCS(s1,s2,s3,i,j,k+1,dp)) );
            return dp[i][j][k];
        }
}

void LCS_(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    vector< vector<int> > dp(n1+1,vector<int> (n2+1 , 0));
    for(int i = 1;i<=n1;i++){
        for(int j = 1;j<=n2;j++){
            if(s1[i - 1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
    }
    // print the common string
    vector<char> result;
    int i = n1,j=n2;
    while(i != 0 and j!= 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            j--;
        }else{
            result.push_back(s1[i-1]);
            i--;j--;
        }
    }
    reverse(result.begin(),result.end());
    for(auto x: result){
        cout<<x;
    }
    cout<<endl;
}
int main(){
    string s1;
    string s2;
    string s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    int dp[100][100][100] = {0};
    for(int i = 0;i<s1.length();i++){
        for(int j = 0;j<s2.length();j++){
            for(int k = 0;k<s3.length();k++){
                dp[i][j][k] = -1;
            }
        }
    }
   cout<< LCS(s1,s2,s3,0,0,0,dp);
    return 0;
}