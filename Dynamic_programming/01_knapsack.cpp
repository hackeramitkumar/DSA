#include<bits/stdc++.h>
using namespace std;



 


int knpasack_01(vector<int>& weight , vector<int>& cost , int W) {
    int n = weight.size();
    assert(cost.size() == n);

    int dp[W+1] = {0};
    for(int i = 0 ; i < n ; i++) {
        for(int j = W ; j >= weight[i] ; j--) {
            dp[j] = max(dp[j] , dp[j-weight[i]] + cost[i]);
        
            /*
                    i = 0 , weight[0] = 1
                    _ _ _ _ _ _ 
                    0 1 2 3 4 5 
                    dp[2] = max(dp[2] , dp[1] + cost[0])
                    dp[1] = max(dp[1] , dp[0] + cost[0])
            

                    _ _ _ _ _ _    
                    0 1 2 3 4 5   
                    dp[5] = max(dp[5] , dp[4] + cost[0])
                    dp[4] = max(dp[4] , dp[3] + cost[0])


                    dp[1] = max(dp[1],dp[0]+cost[0])
                    dp[2] = max(dp[2],dp[1]+cost[0])
                    dp[3] = max(dp[3],dp[2]+cost[0])
                    


            */

        }
    }
    int max1 = 0;
    for(int i = 0 ; i <= W ; i++) {
        max1 = max(max1 , dp[i]);
    }

    return max1;
}

int knapsack_0_oo(vector<int>& weight , vector<int>& cost , int W) {
    int n = weight.size();
    assert(cost.size() == n);

    int dp[W+1] = {0};
    for(int i = 0 ; i < n ; i++) {
        for(int j = weight[i] ; j <= W ; j++) {
            dp[j] = max(dp[j] , dp[j-weight[i]] + cost[i]);
        }
    }
    /*
    dp[2] = max(dp[2], dp[1]+cost[0])
    dp[3] = max(dp[3], dp[2]+cost[0])

    */
                  
    int max1 = 0;
    for(int i = 0 ; i <= W ; i++) {
        max1 = max(max1 , dp[i]);
    }

    return max1;
}


int main(){
    int n,c;
    cin>>n>>c;


    vector<int> item;
    vector<int> value;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        item.push_back(x);
    }
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        value.push_back(x);
    }

    cout<<knapsack_0_oo(item,value,c)<<endl;
}