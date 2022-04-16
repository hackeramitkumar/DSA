#include <bits/stdc++.h>
using namespace std;

// 1. Bubble sort
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. selection sort

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// 3. insertion sort

void insertion_sort(int *arr, int n){
    for(int i = 1;i<n-1;i++){
        int j = i-1;
        int key = arr[i];
        while(j >= 0 and arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. shell sort
void shell_sort(int *arr, int n){
    int interval = n/2;
    while(interval){
        for(int i = interval+1;i< n;i++){
            int key = arr[i];
            int j = i - interval;
            while(j >= 0 and key < arr[j]){
                swap(arr[j], arr[j+interval]);
                j -= interval;
            }
            arr[j+interval] = key;
        }
        interval /= 2;
    }
}



// 5. bucket sort


// 6. radix sort



// 7. count sort


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    shell_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}