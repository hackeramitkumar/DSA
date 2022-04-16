#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
          
    unordered_map<T, list<T>> m;
    // unordered_map<T,list<pair< T, int > > > m;
public:
    // Graph(){
    // }
    void addEdge(T x, T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
        // m[y].push_back(make_pair(x,wt));
    }

    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T, int> dist;

        for (auto node_pair : m)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            // cout<<node<<" ";
            for (auto nbrs : m[node])
            {
                if (dist[nbrs] == INT_MAX)
                {
                    q.push(nbrs);
                    dist[nbrs] = dist[node] + 1;
                }
            }
        } // }cout<<dist[2]<<endl;
        for (auto node_pair : m)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << "is at dist of :" << d << endl;
        }

        // void printAdj(){
        //     for(auto p: m){
        //         cout<<"Vertex "<<p.first<<": ";

        //         for(auto nbr : p.second){
        //             cout<<"( "<<nbr.first<<", "<<nbr.second<<" )";
        //                }
        //         cout<<endl;

        //     }
        // }
    }
};

int main()
{
    // Graph<char> G;
    // G.addEdge('A','C');
    // G.addEdge('B','D');
    // G.addEdge('C','B',50,0);
    // G.addEdge('A','B',50,0);
    // G.addEdge('A','D',60,1);
    // G.printAdj();

    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.bfs(0);
}
