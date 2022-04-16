#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insertValue(node* root,int value,queue<node *> &q ){
    if(value = -1)
{
    return NULL;
}
    node* newRoot =new node(value);
    if(root == NULL){
        root = newRoot;
    }
    // if left child of the current node is avaiable then it will be used
    else if(q.front()->left == NULL){
        q.front()->left = newRoot;
    }
    // now left child of the current node left child is used and if the right child of the current node is available 
   else{
       q.front()->right = newRoot;
       q.pop();
    }
    q.push(newRoot);
    return root;

}


node* buildLevelTree(){
	int d;
	cin>>d;

    queue<node *> q;
    node* root = NULL;

    root = insertValue(root,d,q);
    return root;
}




node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // otherwise print root first followed by subtrees(children)
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

/*
// print kth level
void printKthLevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}
*/
// Print all levels
void printAllLevels(node *root)
{
    int H = height(root);
    for (int i = 1; i <= H; i++)
    {
        // printKthLevel(root, i);
    }
}

void printPostOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}
// O(n*n)
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
        cout << f->data << " ";
        q.pop();
        if (f->left)
        {
            q.push(f->left);
        }

        if (f->right)
        {
            q.push(f->right);
        }
    }

    return;
}

// bfs level wise print
void bfsLevel(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }

    return;
}

//
int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + count(root->left) + count(root->right);
}

// Calculate dimeter optimization

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    // otherWise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

// replace each node by some of child node
int replace(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    // rec case
    int leftSum = replace(root->left);
    int rightSum = replace(root->right);
    int temp = root->data;

    root->data = leftSum + rightSum;
    return temp + root->data;
}

// Height balanced tree
class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHeightBalnce(node *root)
{
    HBPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }

    // recursive case
    HBPair left = isHeightBalnce(root->left);
    HBPair right = isHeightBalnce(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }

    return p;
}

// Building a height balanced binary tree from a array
node *buildtreeFromArray(int *a, int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    // rec case
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildtreeFromArray(a, s, mid - 1);
    root->right = buildtreeFromArray(a, mid + 1, e);
    return root;
}

// building a tree from inorder and preorder traversal
node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }

    // rec case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}

// print right view

void printRightView(node *root, int level, int &maxLevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxLevel < level)
    {
        // have discovered a new level
        cout << root->data << " ";
        maxLevel = level;
    }
    // right
    // left

    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

// binary tree nodes at distance k from a given tareget node
//  print kth level
void printKthLevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

int printAtDistanceK(node *root, node *target, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // reach th taret node
    if (root == target)
    {
        printKthLevel(target, k);
        return 0;
    }

    // next step - ancestor
    int DL = printAtDistanceK(root->left, target, k);
    if (DL != -1)
    {
        // again there are two cases
        // ancestors itselt or we have to go to right to ancestor

        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->right, k - 2 - DL);
        }

        return 1 + DL;
    }

    // if node is not present in left sbtree then it will be in right
    int DR = printAtDistanceK(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->left, k - 2 - DR);
        }

        return DR + 1;
    }

    // node was not present  at left and right side of the subtree given
    return -1;
}

// lowest common ancestors
node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    // search in left and right subtree;
    node *leftAns = lca(root->left, a, b);
    node *rightAns = lca(root->right, a, b);

    if (leftAns != NULL and rightAns != NULL)
    {
        return root;
    }

    // if left node is itself root
    if (leftAns != NULL)
    {
        return leftAns;
    }

    return rightAns;
}

// shortest distance between nodes of a binary tree
//  finding the level of a given node from the root node to given node
int search(node *root, int key, int level)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return level;
    }

    int leftval = search(root->left, key, level + 1);
    if (left != NULL)
    {
        return leftval;
    }
    int rightval = search(root->right, key, level + 1);

    return rightval;
}

// function to find distance between the two nodes

int findDistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);
    int l1 = search(root, a, 0);
    int l2 = search(root, b, 0);

    return l1 + l2;
}

// max sum path from any node to any node
/*

there will be toatal 4 cases
1. only root node
2. root node + left subtree
3. root node + right subtree
4. root node + ls + rs
*/

// using  bottom up approach
class PairSum
{
public:
    int branchSum;
    int maxSum;

    PairSum()
    {
        branchSum = 0;
        maxSum = 0;
    }
};

PairSum maxSum(node *root)
{
    PairSum p;
    if (root == NULL)
    {
        return p;
    }
    PairSum left = maxSum(root->left);
    PairSum right = maxSum(root->right);

    // construct two values
    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = root->data + left.branchSum + right.branchSum;

    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

    // branch sum of the current root
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.branchSum, current_ans_through_root));

    return p;
}

bool isSameTree(node* root1,node* root2){
    if(root1 == NULL and root2 == NULL){
        return true;
    }
    if(root1 != NULL and root2 != NULL){
         int leftAns = isSameTree(root1->left, root2->left);
        int rightAns = isSameTree(root1->right, root2->right);
        return leftAns and rightAns;
    }
    return false;
}

int main()
{

    node *root = buildTree();
        // printPreOrder(root);
    putchar('\n');

    // replace(root);

    // printPreOrder(root);
    bfsLevel(root);
    // int maxLevel = 0;
    // printRightView(root,0, maxLevel);

    // printAtDistanceK(root, root->left, 2);
    // node *lcanode = lca(root, 9, 6);
    // cout << lcanode->data << endl;

    /*

    HBPair pair = isHeightBalnce(root);

    cout << "\n"
         << "Height: " << pair.height << endl;
    cout << "Balance: " << pair.balance << endl;
    Pair p = fastDiameter(root);
    cout << "\n"
         << "Height: " << p.height << endl;
    cout << "Diameter: " << p.diameter << endl;

/*

    int n;
    cin >> n;
    int pre[n];
    int in[n];
    for (int j = 0; j < n; j++)
    {
        cin >> pre[j];
    }


    for (int k = 0; k < n; k++)
    {
        cin >> in[k];
    }


    node *root1 = createTreeFromTrav(in,pre, 0, n - 1);
    bfsLevel(root1);

    */

    // printInOrder(root);
    // putchar('\n');
    // printPostOrder(root);
    // putchar('\n');
    return 0;
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
