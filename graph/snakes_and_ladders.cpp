#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T , list<T> > l;

    public:

    void addEdge(int x,int y){
        l[x].push_back(y);
    }

    int bfs_s(T src, T dest){
        map<T , int > dist;
        
        map<T,T> parent; // this will be used for printing the path of the shoetest throw
        queue<T> q;
        
        for(auto p: l){
            T node = p.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        parent[src] = src;
        dist[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr: l[node]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
       /* for(auto node_pair : l){
            T node = node_pair.first;
            cout<<node<<" and dist is : "<<dist[node]<<endl;
        }
        */

       // print the path 
       T temp = dest;
       while(temp != src){
           cout<<temp<<"<--";
           temp = parent[temp];
       }
       cout<<src<<endl;

       return dist[dest];
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

     // Add edges to the graph
     Graph<int> g;
     for(int i = 0;i<=36;i++) {
         for(int dice = 1;dice <= 6;dice++){
             int j = i + dice;
             j += board[j];

             if(j <= 36){
                 g.addEdge(i,j);
             }
         }
     }
     // in the above loop we will note have any edges to 36 so we have to 
     // handle it seprately. because the above loop will show taht there are nodes till 35

     g.addEdge(36,36);
    //  g.bfs(0);
    cout<< g.bfs_s(0,36)<<endl;
}