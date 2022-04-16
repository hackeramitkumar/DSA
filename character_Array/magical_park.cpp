#include<bits/stdc++.h>
using namespace std;

int solve(char arr[][100],int n,int m,int k,int s){

	int i = 0;
	int j = 0;

	while(i < n){
		while(j < m){
            
			if(arr[i][j] == '.'){
				s = s-2;
            s--;

                if(s<=k){
                    return -1;
                }
				j++;
			}else if(arr[i][j] == '*'){
				s = s+5;
                s--;
				j++;
			}else{
				 i++;
				 j==0;
			}
		}
        j = 0;
        i++;
	}
    
	return s;
}
int main(){
	int n,m,k,s;
    cin>>n>>m>>k>>s;
	char arr[100][100];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>arr[i][j];
		}
	}

    cout<<solve(arr,n,m,k,s);
	

}