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
        l[y].push_back(x);
    }

    void dfs_helper(int src,map<int,int> &visited){
        visited[src] = true;
        cout<<src<<", ";
        for(int nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }

    int dfs_component(T src){
        map<int , int> visited;
        visited[src] = 0;
        for(auto p: l){
            T node = p.first;
            visited[node] = false;
        }
        int cnt = 0;
        for(auto p: l){
            int node = p.first;
            if(!visited[node]){
                cout<<"Component "<<cnt<<"-->";
                dfs_helper(node , visited);
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 3);

    g.addEdge(1, 2);

    g.addEdge(2, 4);

    g.addEdge(1, 4);
     g.addEdge(6,9);
     g.addEdge(9,11);
     g.addEdge(5,20);
     g.addEdge(5,19);

    g.dfs_component(1);
}