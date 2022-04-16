#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }

    void dfs_helper(T src, map<T,bool> &visited, list<T> &ordering){

        visited[src] = true;

        for(auto nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }

        ordering.push_front(src);
    }

    void dfs(){
        map<T,bool> visited;
        list<T> ordering;
        // make all the nodes as not visited
        for(auto p: l){
            T node = p.first;
            visited[node] = false;
        }

        // call the helper function
        for(auto p: l){
            T node = p.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        }
        //finally prin the list
        for(auto node : ordering){
            cout<<node<<endl;
        }
    } 
};

int main()
{

    Graph<int> g;
    g.addEdge(4,2);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(0,5);
    g.dfs();


}