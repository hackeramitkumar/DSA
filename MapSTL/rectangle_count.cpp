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

class Compare{
public:
bool operator()(Point p1, Point p2){
    if(p1.x == p2.x){
        return p1.y<p2.y;
    }
    return p1.x <p2.x;
}

};

int count_rects(vector<Point> cords){
    int n = cords.size();
    // insert all the points in the set
    set<Point,Compare> s;
    for(auto p:cords){
        s.insert(p);
    }
    //Run two loops
    int ans = 0;
    for(auto it = s.begin();it !=prev(s.end());it++){
        for(auto jt = next(it);jt != s.end();jt++){
            Point p1 = *it;
            Point p2 = *jt;

            if(p2.x == p1.x or p2.y == p1.y){
                continue;
            }

            Point p3(p2.x,p1.y);
            Point p4(p1.x,p2.y);

            if(s.find(p3) != s.end() and s.find(p4) != s.end()){
                ans++;
            }

        }
    }

    return ans/2;


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

    int ans = count_rects(cords);
    cout<<ans;

    return 0;

}