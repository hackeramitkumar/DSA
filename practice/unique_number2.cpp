#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        ans ^= arr[i];
    }
    int temp = ans;

  //  extract  the first bit which have 1
  int pos = 0;
  while(ans > 0){
      if((ans & 1) > 0){
          break;

      }
      pos++;
      ans = ans>>1;
  }
  int x = 1<<pos;
int first_ans = 0;
  for(int i = 0;i<n;i++){
      if((x & arr[i] ) == 0){
          first_ans ^= arr[i];
      }
  }
  int second = temp^first_ans;
  cout<<second<<" "<<first_ans<<endl;

}