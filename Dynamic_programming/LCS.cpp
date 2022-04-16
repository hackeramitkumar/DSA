#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2, string s3){
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s2.length();

    int dp[n1+1][n2+1][n3+1];

    int i = n1,j = n2,k = n3;
    while(i != 0 and j != 0 and k != 0){
        if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]){
            dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
        }else{
            dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k], dp[i][j][k-1])) ;
        }
    }
}

void LCS(string s1,string s2){
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
    cin>>s1;
    cin>>s2;
    LCS(s1,s2);
    return 0;
}