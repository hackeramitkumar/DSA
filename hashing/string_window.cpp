#include<bits/stdc++.h>
using namespace std;

string find_window(string s1,string s2){
    int sl = s1.length();
    int pl = s2.length();

    if(pl > sl)
    {
        return "No String";
    }

    // freq. maps
    int fs[256] = {0};
    int fp[256] = {0};

    for(int i = 0;i<pl;i++)
    {
        char ch = s2[i];
        fp[ch]++;
    }
    // window
    int cnt = 0;
    int min_len = INT_MAX;

int start_index = -1;
    int start = 0;   //left pointer for shrinking the window
    for(int i = 0;i<sl;i++)
    {
        char ch = s1[i];
        fs[ch]++;

        //maintain the count of the character matched
        if(fp[ch] != 0 and fs[ch] <= fp[ch]){
            cnt++;
        }

        //if all the character match
        if(cnt == pl){
            //start shrinking the window
            char temp = s1[start];
            //loop to remove all unwanted character
            while(fp[temp] == 0 or fs[temp] > fp[temp]){
                  fs[temp]--;
                  start++;
                  temp = s1[start];
            }

            //window size
            int window_length = i - start + 1;
            if(window_length < min_len){
                min_len = window_length;
                start_index = start;
            }
        }
    }
    if(start_index == -1)
    {
        return "No String";
    }

    string ans = s1.substr(start_index,min_len);
    return ans;

}

int main(){
	string s1;
	string s2;

getline(cin,s1);
    cin>>s2;

    cout<<find_window(s1,s2)<<endl;

}