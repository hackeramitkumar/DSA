#include<bits/stdc++.h>
using namespace std;


vector<int> stock_span(int price[], int n){
vector<int> ans;
    stack<int> s1;
    ans.push_back(1);
    s1.push(0);
    for(int i = 1;i<n;i++){
        int curr_price = price[i];
    
    while(!s1.empty() and price[s1.top()]<= curr_price){
s1.pop();
    }

    if(!s1.empty() ){
int prev_high = s1.top();
ans.push_back(i-prev_high);
    }else{
        ans.push_back(i+1);
    }




s1.push(i);


    }

    return ans;






}
int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i = 0;i<n;i++){
        cin>>price[i];
    }

    vector<int> v = stock_span(price,n);
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;

}