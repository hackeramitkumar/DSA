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
    void bfs(T src)
    {
        unordered_map<T, int> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();
            for (int nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    // mark the nbr as the visited
                    visited[nbr] = true;
                }
            }
        }
        cout << endl;
    }
    void bfs_shortest_path(T src)
    {
        unordered_map<T, int> dist;
        queue<T> q;
        for(auto p: l){
            T node = p.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            T node = q.front();
            // cout << node << " ";
            q.pop();
            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    // mark the nbr as the visited
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        //print the dist to every node
        for(auto node_pair : l){
            T node  = node_pair.first;
            int dis = dist[node];
            cout<<"Node "<<node<<" dist from src is : "<<dis<<endl; 
        }

    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 3);

    g.addEdge(1, 2);

    g.addEdge(2, 4);

    g.addEdge(1, 4);

    g.bfs_shortest_path(1);
}