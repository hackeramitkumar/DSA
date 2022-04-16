#include<bits/stdc++.h>
using namespace std;

int maximum_length_sub(string str,int k){
    int freq[26] = {0};
    int len = -1;
    int cnt  = 0;

    int i = 0;

    for(int j = 0; str[j] != '\0';j++){
        freq[str[j] - 'a']++;
        if(freq[str[j] - 'a'] == 1){
            cnt++;
        }
        while(cnt > k){
            freq[str[i]-'a']--;
            if(freq[str[i] - 'a'] == 0){
                cnt--;
            }  
            i++;


        }
        if(cnt == k){
            len = max ( len , j - i +1);
        }
    }
    return len;


}
int main(){
    int k;
    string str;
    cin>>str;
    cin>>k;
    cout<<maximum_length_sub(str,k);

}