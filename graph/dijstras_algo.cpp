#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, int> > > m;

    public:

    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
        m[v].push_back(make_pair(u,dist));
        }
    }

    void dijkstra(T src){
        unordered_map<T, int> dist;

        //set all the distance to oo
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
    
    
        // make a set to find minimum distance
        set<pair< int , T> > s;
        dist[src] =0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            // find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over neighbours of the current node
            for(auto childpair: m[node]){
                if(nodeDist + childpair.second < dist[childpair.first]){
                    // int he set updation of a particular is not possible
                    // we have to remove the old pair  and insert the new pair to simulation updation

                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!= s.end()){
                        s.erase(f);
                    }
                    // insert the new pair
                    dist[dest] = nodeDist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        //print the dist
        for(auto d: dist){
            cout<<d.first<<" --> "<<d.second<<endl;
        }
    }
};



int main(){
    Graph<string> g;
    g.addEdge("A","B",4);
    g.addEdge("A","C",1);
    g.addEdge("B","C",2);
    g.addEdge("B","D",8);
    g.addEdge("D","E",3);
    g.addEdge("E","F",2);
    g.addEdge("C","F",1);

    g.dijkstra("A");


}