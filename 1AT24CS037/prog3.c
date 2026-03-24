#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int l = low;
    int h = high;
    int pivot = a[low];

    while (l < h)
    {
        while (l <= high && a[l] <= pivot)
            l++;

        while (a[h] > pivot)
            h--;

        if (l < h)
            swap(&a[l], &a[h]);
    }

    swap(&a[low], &a[h]);

    QuickSort(a, low, h - 1);
    QuickSort(a, h + 1, high);
}

int main()
{
    long int n = 10000;
    int it = 0;
    double tim3[10];

    srand(time(NULL));

    printf("Array Size,QuickSort Time(ms)\n");

    while (it < 10)
    {
        int *c = (int *)malloc(n * sizeof(int));

        for (long int i = 0; i < n; i++)
        {
            c[i] = rand() % n + 1;
        }

        clock_t start, end;

        start = clock();
        QuickSort(c, 0, n - 1);
        end = clock();

        tim3[it] = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("%ld,%lf ms\n", n, tim3[it]);

        free(c);

        n += 10000;
        it++;
    }

    return 0;
}