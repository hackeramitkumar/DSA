#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    int fre;
    bool terminal;
    Node(char d){
        data = d;
        terminal = false;
    }
};

class Trie{
    Node* root;
    int cnt;

    public:
    Trie(){
        root = new Node('\0');
        cnt = 0;
    }
    void insert(char *w){
        Node* temp = root;
        for(int i = 0;w[i]!= '\0';i++){
            char ch=w[i];
            if(temp -> children.count(ch)){
                temp = temp->children[ch];
                temp->fre += 1;
            }else{
                Node* n = new Node(ch);
                temp -> children[ch] = n;
                temp = n;
                temp->fre = 1;
            }
        }
        temp->terminal = true;
    }

    vector<string> prefixSol(){
        Node* temp = root;
    }
};

int main(){
    Trie t;
    char words[][10] = {"a","hello","three","four"};
    char w[10];
    cin>>w;
    for(int i = 0;i<4;i++){
        t.insert(words[i]);
    }
   

}