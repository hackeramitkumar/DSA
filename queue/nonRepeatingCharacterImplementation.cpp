#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin>>ch;

    while(ch!='.'){
        //login will go there
        //insert in queue and freq table
        q.push(ch);
        freq[ch-'a'] ++;

        //query
        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx] > 1){
                q.pop();
            }else{
                cout<<q.front()<<endl;
                break;
            }
        }

        //if q will beacame empty this implies that there is not such characteer till now which is non repeating
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;



    }
    return 0;
}