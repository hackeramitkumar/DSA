#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(int *a,int *b,int *c,int s,int e)
{
	int mid = (s+e)/2;
	int i =s;
	int j = mid +1;
	int k = s;

	while(i <= mid and j<= e)
	{
		if(b[i] <= c[j]){
			a[k++] = b[i++];
		}else {
			a[k++] = c[j++];
		}
	}
	while(i<=mid){
		a[k++] = b[i++];
	}
	while(j <= e)
	{
		a[k++] = c[j++];
	}
}

void mergeSort(int *arr,int s,int e){
	//base case
	if(s>=e)
	{
		return ; 
	}

	//recursive
	int b[100000],c[100000];
	int mid =(s+e)/2;
	for(int i = s;i<=mid;i++)
	{
		b[i] = arr[i];
	}

	for(int i = mid ; i <= e;i++)
	{
		c[i] = arr[i];
	}

	//sort - pure assumption
	mergeSort(b,s,mid);
	mergeSort(c,mid+1,e);

	//merge the both 
	merge(arr,b,c,s,e);
}
int main()
{
	int n;
	cin>>n;
	int arr[200000];
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	mergeSort(arr,0,n-1);
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i] <<" ";

	}
	putchar('\n');
}