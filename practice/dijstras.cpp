#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    unordered_map<T , list<psir<T, int> > > l;
    public:
    void addEdge(T u , T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v,wt));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
};


int main(){

}