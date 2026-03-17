#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves
void merge(long int a[], int low, int mid, int high) 
{
    int i = low, j = mid + 1, k = low;
    long int b[100000];   // Temporary array

    while (i <= mid && j <= high) 
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

// Main mergeSort function
void mergeSort(long int a[], int low, int high) 
{
    if (low < high) 
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main() 
{
    long int n = 10000;
    int it = 0;
    double tim3[10];

    srand(time(NULL));

    printf("A_size, MergeSort Time\n");

    while (it < 10) {

        long int c[n];

        // Generate random numbers
        for (long int i = 0; i < n; i++) 
        {
            long int no = rand() % n + 1;
            c[i] = no;
        }

        clock_t start, end;

        start = clock();
        mergeSort(c, 0, n - 1);   // corrected array name
        end = clock();

        tim3[it] = ((double)(end - start)) / CLOCKS_PER_SEC * 10000;

        printf("%li, %li ms\n", n, (long int)tim3[it]);

        n += 10000;
        it++;
    }

    return 0;
}

// arr[k] = R[j]; j++;}
