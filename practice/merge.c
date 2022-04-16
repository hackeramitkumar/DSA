#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(long int arr[],long int l,long int m,long int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[],long int l,long int r)
{
    if (l < r)
    {

        long int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}








int main()
{
    long int n = 1000;
    int it = 0;
    double t[100];
    while (it < 100)
    {
        long int a[n];
        for (int i = 0; i < n; i++)
        {
            long int num = rand() % n + 1;
            a[i] = num;
        }
        clock_t start, end;
        start = clock();
        mergeSort(a,0,n-1);
        end = clock();
        t[it] = ((double)(end - start));

        printf("%li %li \n", n, (long int)t[it]);
        n = n + 1000;
        it++;
    }

    return 0;
}