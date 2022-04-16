#include<bits/stdc++.h>
using namespace std;

int find_first_set_bit(int n){
    int ans = 0;
    int i = 0;
    while(n>0){
        if(n&1){
            break;
        }
        i++;
        n = n >> 1;
    }
    ans = 1 << i;
    return ans;
}
vector<int> find_nums(int sum, int n){
    vector<int> ans;
    while(sum >0 and n>0){
        if((sum - find_first_set_bit(n)) >= 0 ){
            sum = sum - find_first_set_bit(n);
            ans.push_back(n);
        }
        n--;
    }
    if(sum > 0){
        ans.clear();
        ans.push_back(-1);

    }
    return ans;

}
int main(){

int sum,n;
cin>>sum>>n;
vector<int> sol = find_nums(sum,n);
if(sol[0] == -1){
    cout<<-1<<endl;
    return 0;
}
cout<<sol.size()<<endl;
for(int i = 0;i<sol.size();i++){
    cout<<sol[i]<<" ";
}
cout<<endl;
return 0;
}
