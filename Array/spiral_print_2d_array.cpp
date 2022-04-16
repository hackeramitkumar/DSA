#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

 void print(int arr[][10], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;
 
    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";
 
    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
 
    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
 
    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
 
    print(arr, i + 1, j + 1, m - 1, n - 1);
}
 
/*
void printSpiral(int arr[R][C],int m,int n)
{
    int r =0,c=0;

    while(r<m && c<n)
    {
        for(int i = r;i<m;i++)
        {
            cout<<arr[i][c]<<", ";
        }
        c++;
        for(int i = c;i<n;i++)
        {
            cout<<arr[m-1][i]<<", ";
        }
        m--;

        // if(c<n){
        for(int i = m-1;i>=r;i--)
        {
            cout<<arr[i][n-1]<<", ";
        }
        n--;
        // }
        // if(r<m){
        for(int i = n-1;i>=c;i--)
        {
            cout<<arr[r][i]<<", ";
        }
        r++;
    // }
    }
    cout<<"END"<<endl;
    
}
*/

// int main()
// {
    
//     int arr[R][C];
//     for(int i= 0;i<R;i++){
//         for(int j = 0;j<C;j++){
//             cin>>arr[i][j];
//         }
//     }
//     printSpiral(arr,R,C);
//     print(arr, 0, 0, R, C);

//     return 0;
   
    

// }
//clock wise

/*
#include<bits/stdc++.h>
using namespace std;

void spiral_print(int arr[][10],int m,int n)
{
	int sr = 0,er = m-1,sc = 0,ec = n-1;
	while(sr<=er and sc<=ec)
	{
		for(int i = sc;i<=ec;i++)
		{
			cout<<arr[sr][i]<<", ";
		}
		sr++;
		for(int i = sr;i<=er;i++)
		{
			cout<<arr[i][ec]<<", ";
		}
		ec--;
		if(sr<er){
		for(int i = ec;i>=sc;i--)
		{
			cout<<arr[er][i]<<", ";
		}
		er--;
		}

		if(sc<ec){
		for(int i = er;i>=sr;i--)
		{
			cout<<arr[i][sc]<<", ";
		}
		sc++;

		}

	}
	cout<<"END\n";
}
*/

int main()
{
int arr[10][10];
int m, n;
cin>>m>>n;


for(int i = 0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		cin>>arr[i][j];
	}
}
print(arr,0,0,m,n);
return 0;

}