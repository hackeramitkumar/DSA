#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node *left; // for 0

    node *right; // for 1
};

class trie{
    node* root;
    public:
    trie(){
        root = new node();
    }

    // insert function    5 ->  0 0 0 0 0 1 0 1   [32 bit integer]
    void insert(int n){
        node* temp = root;
        for(int i = 31;i>=0;i--){
            int bit = (n>>i) & 1; // this will move the MSB to the ith position right

            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }else{
                //bit is 1
                if(temp -> right == NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    //HELPER METHODE
    int max_xor_helper(int value){
        int current_ans = 0;
        node* temp = root;
        for(int i = 31;i>=0;i--){
            int bit = (value>>i) &1;

            if(bit == 0){
                //find a complementary value
                if(temp->right != NULL){
                    temp = temp->right;
                    current_ans += (1<<i);
                }else{
                    temp = temp->left;
                }
            }else{
                //current bit is 1
                if(temp -> left != NULL){
                    temp = temp->left;
                    current_ans += (1<<i);
                }else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    // final methode
    int max_xor(int *input,int n){
        int max_xor = 0;
        for(int i = 0;i<n;i++){
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            cout<<current_xor<<" ";
            max_xor = max(max_xor,current_xor);
        }
        putchar('\n');

        return max_xor;
    }
};
int main(){

    int arr[] = {8,10,2};
    int n = sizeof(arr)/sizeof(int);
    trie t;

    cout<<t.max_xor(arr,n)<<endl;
    
}