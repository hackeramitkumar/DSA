#include<bits/stdc++.h>
using namespace std;

string extractStringFromKey(string str,int key){

    char *s = strtok((char *)str.c_str()," ");
    while(key > 1){
        s = strtok(NULL," ");
        key--;
    }
    return (string)s;
}
bool compare(pair<string,string> s1,pair<string,string > s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2 ;
}

bool compare(pair<string,string> s1,pair<string,string > s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToint(key1) < convertToInt(key2) ;
}

int main(){
    int n;
    string str[n];
    for(int i = 0;i<n;i++){
        cin>>str[i];
    }
}