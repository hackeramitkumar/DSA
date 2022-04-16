#include<bits/stdc++.h>
using namespace std;
/*
void readLines(char arr[],char delimiter)
{
    int i = 0;
    char ch = cin.get();
    while(ch!= delimiter)
    {
        
        arr[i] = ch;
        i++;
        ch = cin.get();
        if(ch>='A'&&ch<='Z')
        {
            arr[i]='\n';
            i++;
        }
    }
    arr[i] = '\0';
}

*/

int main()
{
    char a[1000];
  cin.getline(a,1000);
  cout<<a[0];
  for(int i = 1;i<strlen(a);i++)
  {
      char ch = a[i];
      if(ch>='A' && ch<='Z')
      {
          cout<<"\n";
      }
      cout<<ch;

  }
  

cout<<endl;
    return 0;
}