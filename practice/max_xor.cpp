
#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    node* left;
    node* right;
};

class Trie{
    public:
  
    node* root;
    
    public:
    Trie(){
        root = new node();
    }
    
    void insert(int n){
        node* temp = root;;
        for(int i = 31;i>= 0;i--){
            int bit = (n>>i) & 1;
            
            
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }else{
                if(temp->right == NULL){
                    temp->right = new node();
                }
                    temp = temp->right;
        }
    }

    }
    int max_xor_helper(int value){
        int curr_ans = 0;
    node* temp = root;
        for(int j = 30;j>=0;j--){
            int bit =( value >> j) & 1;
            if(bit == 0){
                if(temp->right != NULL){
                    temp = temp->right;
                    curr_ans += (1<<j);
                }else{
                    temp = temp ->left;
                }
            }else{
                if(temp -> left != NULL){
                    temp = temp->left;
                    curr_ans += (1<<j);
                }else{
                    temp = temp -> right;
                }
            }
        }
        return curr_ans;
    }
    
    
    int max_xor(vector<int> v){
        int max_xor = 0;
        for(int i = 0;i<v.size();i++){
            insert(v[i]);
            max_xor = max(max_xor, max_xor_helper(v[i]));
        }
        return max_xor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = t.max_xor(nums);
        return ans;
        
    }
};

int main(){
    vector<int> v({3,10,5,25,2,8});
    Solution s;
    cout<<s.findMaximumXOR(v);
}