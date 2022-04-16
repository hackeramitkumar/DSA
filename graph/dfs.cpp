#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);
    }

    void dfs_helper(int src, unordered_map<int,int> &visited){
        visited[src] = true;
        cout<<src<<", ";
        for(int nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(T src){
        unordered_map<int , int> visited;
        visited[src] = 0;
        for(auto p: l){
            T node = p.first;
            visited[node] = false;
        }
        dfs_helper(src,visited);
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 3);

    g.addEdge(1, 2);

    g.addEdge(2, 4);

    g.addEdge(1, 4);

    g.dfs(1);
}