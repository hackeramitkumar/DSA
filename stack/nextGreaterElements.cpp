#include<bits/stdc++.h>
using namespace std;

void NextGreaterElement(int *arr,int *nge,int n){
    stack<int> s;
    int i = 0;

    while(i<2*n){
        // If stack is not empty and
        // current element is greater
        // than top element of the stack
        while(!s.empty() && arr[i%n] > arr[s.top()]){
            // Assign next greater element
            // for the top element of the stack
            nge[s.top()] = arr[i%n];

            //pop the top element of the stack
            s.pop();
        }
        s.push(i % n);
        i++;
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int nge[n] ;
    for(int i = 0;i<n;i++){
        nge[i] = -1;
    }

    NextGreaterElement(arr,nge,n);
    for(int i = 0;i<n;i++)
    {
        cout<<nge[i]<<" ";
    }
    putchar('\n');
}