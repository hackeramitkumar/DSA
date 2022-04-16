#include<bits/stdc++.h>
using namespace std;
char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
  void print_word(char arr[],char *out,int i, int j){
      if(arr[i] == '\0'){
          out[j] = '\0';
          cout<<out<<" ,";
          return;
      }

      int digit = arr[i] - '0';
      if(digit == 0 || digit == 1){
          print_word(arr,out,i+1,j);
      }



      for(int k = 0;keypad[digit][k] != '\0';k++){
          out[j] =  keypad[digit][k];
          print_word(arr,out,i+1,j+1);

        //   out[j] = '\0';
        //   print_word(arr,out,i,j);
      }
  }






int main(){
    char str[10];
    cin>>str;
    char out[10];
    print_word(str,out,0,0);

}