#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];

    }
     void addEdge(int x, int y,bool directed = true){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool bfs_check(){
        int *visited = new int[V];
        int *parent = new int[V];

    for(int i = 0;i<V;i++)
{
    visited[i] = false;
}        queue<int> q;
        q.push(0);
        visited[0] = true;


        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr : l[node]){
                if(visited[nbr] == true and parent[nbr] != node)
            }

        }

    }

};
int main(){

}