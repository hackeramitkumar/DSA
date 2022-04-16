#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
// Swap function
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 1. Bubble sort
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 2. selection sort

void selectionSort(int *arr, int n)
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
        swap(&arr[i], &arr[min]);
    }
}

// 3. insertion sort

void insertionSort(int *arr, int n){
    for(int i = 1;i<n-1;i++){
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main()
{

   int n = 1000;
    int t = 3;
  
    double tim1[3], tim2[3], tim3[3];
  
    printf("Array size |   Bubble    |  Insertion  | Selection\n");
  
    
    while (t--) {
        int a[n], b[n], c[n];
  
        // generating n random numbers
        // storing them in arrays a, b, c
        for (int i = 0; i < n; i++) {
            int no = rand();
            a[i] = no;
            b[i] = no;
            c[i] = no;
        }
  
        
        clock_t start, end;
  
        
        start = clock();
        bubbleSort(a, n);
        end = clock();
  
        tim1[t] = ((double)(end - start));
  
    
        start = clock();
        insertionSort(b, n);
        end = clock();
  
        tim2[t] = ((double)(end - start));
  

        start = clock();
        selectionSort(c, n);
        end = clock();
  
        tim3[t] = ((double)(end - start));
  
    
        printf("%d, %li, %li, %li\n",
               n,
               (long int)tim1[t],
               (long int)tim2[t],
               (long int)tim3[t]);
  
        // Increase the size of array by a factor of 10
        n *= 10;
    }
  
    return 0;


    
}