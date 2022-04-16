#include<bits/stdc++.h>
using namespace std;
#define ll long long


int partition(int *a,int s,int e) {
    int i = s-1;
    for(int j = s;j<e;j++)
    {
        if(a[j]<=a[e])
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1] , a[e]);
    return i+1;
}
void quickSort(int *a,int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }

    // rec case
    int index = partition(a,s,e);
    quickSort(a,s,index-1);
    quickSort(a,index+1,e);
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
	
	quickSort(arr,0,n-1);
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i] <<" ";

	}
	putchar('\n');
}