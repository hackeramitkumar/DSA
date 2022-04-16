#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<pair<int,int> > *l;
    int V;

    public:
    Graph(int V){
        l = new vector<pair<int,int> > [V];
        this -> V = V;
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});


    }

    int prim_mst(){
        // most impotsnt stuff 
        // init a min heap
        priority_queue<pair < int, int > , vector< pair<int , int > > , greater < pair < int , int > > > Q;
        // visited array that denotes that whether a node has been included in MST or not

        bool *visited = new bool[V]{0};
        int ans = 0;

        Q.push({0,0}); // weight , node

        while(!Q.empty()){
            // pich out the edge with min weight
            auto best = Q.top();
            Q.pop();
            int to = best.second;
            int weight = best.first;

            if(visited[to]){
                // discard the edge and continue;
                continue;
            }
            // otherwise take the current edge
            ans += weight;
            visited[to] = 1;
            // add the new edge in the queue
            for(auto x : l[to]){
                if(visited[x.first] == 0) {
                    Q.push({x.second , x.first });
                }
            }

        }
        return ans;
    }
};
int main(){
    

}