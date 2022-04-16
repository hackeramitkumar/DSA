#include<bits/stdc++.h>
using namespace std;
 class Graph{
     list<pair<int,int> > l;
int V;
     public:
     Graph(int V){
         this->V = V;
     }
     void addEdge(int u, int v){
         l.push_back(make_pair(u,v));
     }

     int findSet(int i , int parent[]){
         if(parent[i] == -1){
             return i;
         }
         return findSet(parent[i], parent);
     }

     void unionSet(int x , int y, int *parent){
         int s1 = findSet(x,parent);
         int s2 = findSet(y,parent);

         if(s1!=s2){
             parent[s1] = s2;
         
         }

     }

     bool contains_cycle(){
         int *parent = new int[V];
         for(int i = 0;i<V;i++){
             parent[i] = -1;
         }

         // iterate over the edgelist
         for(auto edge : l){
             int i = edge.first;
             int j = edge.second;

             int s1 = findSet(i,parent);
             int s2 = findSet(j,parent);

             if(s1!= s2){
                 unionSet( s1 ,s2, parent);
             }else{
             cout<<"Same parent : "<<s1 << " and "<<s2;
             return true;
         }

         }
         delete parent;
         return false;
     }

 };

int main(){
    int 
}