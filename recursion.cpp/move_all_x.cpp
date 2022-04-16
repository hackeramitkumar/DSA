#include<bits/stdc++.h>
using namespace std;

void move_all_x(char *str,int i)
{//base case
if(str[i] == '\0')
{
	cout<<str<<endl;
	return;
}

	//rec case
	if(str[i] == 'x')
	{
		int j = i+1;
		while(str[j] == 'x' && str[j] != '\0'){
			j++;
		}
        if(str[j] != '\0'){
		swap(str[i],str[j]);
        }
	}
move_all_x(str,i+1);
}


int main()
{
    char str[1000];
	cin>>str;
	move_all_x(str,0);
	return 0;
}