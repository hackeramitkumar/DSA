#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int arr[100000];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;

    deque<int> Q(k);
    int i;
    for( i = 0;i<k;i++){
        while(!Q.empty() && arr[i] > arr[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    //process the remaining elements
    for(;i<n;i++){
        cout<<arr[Q.front()]<<" ";

        //1. remove the elements which are not the parts of the window
        while(!Q.empty() && (Q.front()<=(i-k))){
            Q.pop_front();
             
        }

        //2.remove the elements which are not useful and are in window
        while(!Q.empty() && arr[i] >= arr[Q.back()]){
            Q.pop_back();
        }

        //3. Add the new elements
        Q.push_back(i);
    }
    // print the maximum of the last window
    cout<<arr[Q.front()]<<endl;
    return 0;
}