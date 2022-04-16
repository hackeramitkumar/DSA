#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x,y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

int count_triangles(vector<Point> cords){
    int n = cords.size();
    // insert all the points in the set
    unordered_map<int,int> xp;
    unordered_map<int,int> yp;

    for(auto p:cords){
        xp[p.x] += 1;
        yp[p.y] += 1;

    }
    
    //Run two loops
    int ans = 0;
    for(auto it = cords.begin();it != cords.end();it++){
        Point p1 = *it;
        ans += (xp[p1.x]-1)*(yp[p1.y]-1);
    }

    return ans;
}

int main(){
    int m;
    cin>>m;

    vector<Point> cords;
    while(m--){
        int x,y;
        cin>>x>>y;
        Point p(x,y);
        cords.push_back(p);
    }

    int ans = count_triangles(cords);
    cout<<ans;

    return 0;

}