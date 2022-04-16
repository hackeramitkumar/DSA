#include<bits/stdc++.h>
using namespace std;


class Graph{
    map<int, list<int> > l;

    public:
    void addEdge(int x,int y){
        l[x].push_back(y);
    }

    int bfs_s(int src,int dest){
        queue<int> q;
        map<int , int> dist;
        map<int,int> parent; // this will be used for printing the path of the shoetest throw

        for(auto p: l){
            int node = p.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                    
                }
            }
        }

        int temp = dest;
        while(temp != src){
            cout<<temp<<"<--";
            temp = parent[temp];

        }
        cout<<endl;
        return dist[dest];
    }
};
int main(){
    int board[50] = {0};

     // snakes -> -ve  
     // ladders -> +ve
     board[2] =  13;
     board[5] = 2;
     board[9] = 18;
     board[18] = 11;
     board[17] = -13;
     board[20] = -14;
     board[24] = -8;
     board[25] = 10;
     board[32] = -2;
     board[34] = -22;
     Graph g;

     for(int i = 0;i<= 36;i++){
         for(int dice = 1;dice <= 6;dice++){
             int j = i + dice;
             j += board[j];
             if(j <= 36){
                 g.addEdge(i,j);

             }
         }
     }
     g.addEdge(36,36);
     cout<<g.bfs_s(0,36);
}