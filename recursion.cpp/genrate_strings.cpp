#include<bits/stdc++.h>
using namespace std;

 
void genrate_strings(char *inp,char *out,int *cnt,int i,int j)
{

    
	//base case
if(inp[i] == '\0'){
	out[j] = '\0';

    (*cnt)++;
	cout<<out<<" ";
    return;
}
	//rec case
	genrate_strings(inp,out,cnt,i+1,j);

	out[j] = inp[i];
	genrate_strings(inp,out,cnt,i+1, j+1);
}
int main()
{
	char str[100];
    char out[100];
    int cnt = 0;
	cin>>str;
	genrate_strings(str,out,&cnt,0,0);
    putchar('\n');
    cout<<cnt<<endl;
	return 0;
}