#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int n, f, d;
    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back(make_pair(d, f));
    }
    int D, F;
    cin >> D >> F;
    // modify the distance from village to distance from forest
    for (int i = 0; i < n; i++)
    {
        v[i].first = D - v[i].first;
    }

    sort(v.begin(), v.end(), compare);

    //prev denotes the pre pump we have visited
    int prev = 0;
    int x = 0;
    int ans = 0;
    int flag = 0;

    while(x<n){
        //if we have enough fuel to go to the next pump
        if(F>= (v[x].first - prev)){
            F = F - (v[x].first - prev);
            pq.push(v[x].second);
            prev = v[x].first;
        }else{
            // now we will check that if we have a pupm already visited and then we take fuel from which we have largest value
            if(pq.empty()){
                flag = 1;
                break;
            }
            //otherwise refuel the tank
            F += pq.top();
            pq.pop();
            ans = ans + 1;
            continue;
        }
        x++;
    }
    if(flag = 1){
        cout<<-1<<endl;
        return 0;
    }
    D = D - v[n-1].first;
    if(F >= D){
        cout<<ans<<endl;
        return 0;
    }

    while(F < D){
        if(pq.empty()){
            flag = 1;
            break;
        }
        F += pq.top();
        pq.pop();
        ans = ans + 1;
    }

    if( flag == 1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;

return 0;

}
