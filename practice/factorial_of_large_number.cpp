#include<bits/stdc++.h>
using namespace std;

void multiply_num(int num, int *fact,int &len){
    int carry = 0;
    for(int i = 0;i<len;i++){
        int curr = fact[i]*num + carry;
        fact[i] = curr%10;
        carry = curr / 10;

    }
        while(carry>0){
            fact[len] = carry%10;
            len++;
            carry = carry/10;
        }
}

int main(){
    int n;
    cin>>n;
    int fact[100000] = {1};
    int len = 1;
    for(int i = 2;i<=n;i++){
        multiply_num(i,fact,len);
    }
    for(int i = len-1;i>=0;i--){
        cout<<fact[i];
    }
    cout<<endl;
    return 0;

}