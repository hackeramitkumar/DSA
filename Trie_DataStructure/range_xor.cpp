#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	node *left;
	node* right;
    list<int> indexes;
};

class Trie{
	node* root;
	public:
	Trie(){
		root = new node();
	}
	void insert(int n,int idx){
		node* temp = root;
		for(int i = 31;i>=0;i--)
		{
			int bit = (n>>i)&1;
			if(bit == 0){
				if(temp->left == NULL){
					temp->left = new node();
				}
                temp->indexes.insert(idx);
				temp = temp->left;
			}else{
				if(temp->right == NULL){
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
	}

	// helper function
	int max_xor_helper(int value){
		node* temp = root;
		int current_ans = 0;
		for(int j = 31;j>=0;j--){
			int bit = (value>>j)&1;
			if(bit == 0){
				//find a complementry value
				if(temp->right != NULL){
					temp = temp->right;
					current_ans += (1<<j);
				}else{
					temp = temp->left;
				}
			}else{
				if(temp->left != NULL){
					temp = temp->left;

				}else{
					temp = temp->right;
					current_ans += (1<<j);
				}
			}
		}
		return current_ans;
	}

	int max_Xor(int *input,int s,int n,int x){
		int ans = 0;
		for(int i = s;i<n;i++){
			int val = input[i];
			insert(val);
		}

		int ans = max_xor_helper(x);
		return ans;
	}

};



int main(){
	int t;
	vector<int> v;
	v.push_back(0);
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		if(q== 0)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}else{
			int L,R,X;
			cin>>L>>R>>X;



			
		}
	}
}