#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[][100],int n)
{
	for(int row = 0;row<n;row++){
	int x= 0,y = n-1;
	{
		while(x<y)
		{
			swap(arr[row][x],arr[row][y]);
			x++;
			y--;
		}

	}
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			if(i<j)
			{
				swap(arr[i][j],arr[j][i]);
			}
		}
	}

	}
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		putchar('\n');
	}
	
	
	
}

int main()
{
	int arr[100][100];
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	 rotate(arr,n);
     return 0;
}