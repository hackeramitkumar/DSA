#include<bits/stdc++.h>
using namespace std;
void targetSum(int arr[], int n, int target)
{
    sort(arr,arr+n);
for(int i = 0;i<n-2;i++){
    int left = i+1;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right] + arr[i];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target) 
        {
            left++;
        }
        else
        {
            cout << arr[i]<<", "<<arr[left] << " and " << arr[right] << endl;
            left++;
            right--;
        }
    }
}

}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cin>>x;
	targetSum(arr,n,x);
	return 0;
}