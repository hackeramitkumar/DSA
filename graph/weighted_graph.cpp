#include<bits/stdc++.h>
using namespace std;

class Graph{
    //take a map which will store the key and the a pair for that key
    unordered_map<string ,list<pair<string , int> > >l;

    public:
    void addEdge(string x,string y, int wt, bool bidir){
        l[x].push_back(make_pair( y, wt));
        if(bidir){
        l[y].push_back(make_pair( x, wt));
        }
    }

    void printAdjList(){
        for(auto p : l){
            string city = p.first;
            list<pair<string,int> > nbrs= p.second;
            cout<<city<<"--> ";
            for(auto nbr: nbrs){
                string dest = nbr.first;
                int dist = nbr.second;
                cout<<" ( "<<dest<<" "<<dist<<" ), ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",5,true);
    g.addEdge("A","D",90,false);
    g.addEdge("c","B",50,true);
    g.addEdge("A","c",80,true);
    g.addEdge("D","c",80,true);

    g.printAdjList();





}