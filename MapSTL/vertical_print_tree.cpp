#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node* buildTree()
{
    int d;
    cin>>d;
    if(d == -1)
    {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void verticalPrint(node* root,int d , map<int,vector<int> > &m){
    //base case
    if(root == NULL)
    {
        return;
    }

    //rec case
    m[d].push_back(root->data);
    verticalPrint(root->left,d-1,m);
    verticalPrint(root->right,d+1,m);

    return;
}

int main()
{
    node* root = buildTree();
    map< int,vector<int> > m;

    int d = 0;
    verticalPrint(root,d,m);

    // print the vertical order
    for(auto p:m)
    {
        cout<<p.first<<"--->";
        for(int x:p.second){
            cout<<x<<", ";
        }
        cout<<endl;
    }


}