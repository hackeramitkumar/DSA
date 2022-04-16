#include<bits/stdc++.h>
using namespace std;

void stockSpan(int *prices,int n,int *span){
    stack<int>s;
    s.push(0);
    span[0] = 1;
    int i;
    //loop for rest of days
    for(i = 1;i<=n-1;i++){
        int currentPrice = prices[i];
        //top most element that is higher than current prices 
        while(!s.empty() and prices[s.top()] <= currentPrice) {
            s.pop();
        }

        if(!s.empty()){
            int pre_highest = s.top();
            span[i] = i - pre_highest;
        }else{
            span[i] = i+1;
        }
        // push this element into the stuck
        s.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    int prices[1000000];
    for(int i = 0;i<n;i++){
        cin>>prices[i];
    }

    int span[1000000];
    stockSpan(prices,n,span);
    for(int i= 0;i<n;i++){
        cout<<span[i]<<" ";
    }
    cout<<"END"<<endl;
	return 0;

}