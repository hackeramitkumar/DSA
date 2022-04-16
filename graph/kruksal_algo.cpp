#include<bits/stdc++.h>
using namespace std;
 class DSU{
     int *parent;
     int *rank;

     public:
     DSU(int V){
         parent = new int[V];
         rank = new int[V];

         for(int i = 0;i<V;i++){
             parent[i] = -1;
             rank[i] = 1;
         }
     }

     int findSet(int i){
         if(parent[i] == -1){
             return i;
         }
         return parent[i] = findSet(parent[i]);
     }

     void unionSet(int x , int y){
         int s1 = findSet(x);
         int s2 = findSet(y);

         if(s1!=s2){
             if(rank[s1] < rank[s2]){
                 parent[s1] = s2;
                 rank[s2] += rank[s1];
             }else{
                 parent[s2] = s1;
                 rank[s1] += rank[s2];
             }

         
         }

     }

 };

 class Graph{
     vector<vector<int > > edgelist;
     int V;
     public :
     Graph(int V){
         this->V = V;
     }
     void addEdgeList(int x, int y, int wt){
         edgelist.push_back({x,y,wt});
     }
     int kruksal_MST(){
         // main logic - easy
         // 1. sort the edgelist on the bases of th et odf the edges
         sort(edgelist.begin(),edgelist.end());
         int ans = 0;
         // init a DSU
         DSU s(V);

         for(auto edge : edgelist){
             int w = edge[0];
             int x = edge[1];
             int y = edge[2];

             // take that edge in mst if it does not form cycle
             if(s.findSet(x) != s.findSet(y) ){
                 s.unionSet(x,y);
                 ans += w;
             }

         }
         return ans;
     }
 };

int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(1,4);
    g.addEdge(3,2);
    g.addEdge(4,2);
    g.addEdge(0,2);



}