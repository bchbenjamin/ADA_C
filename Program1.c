#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap (long int*a,long int*b)
{
    long int temp=*a;
    *a=*b;
    *b=temp;
}

void selection(long int arr[],long int n)
{
    long int i,j,midx;
    for(i=0;i<n-1;i++)
    {
        midx=1;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[midx])
                midx=j;
        swap(&arr[midx],&arr[i]);
    }
}

int main()
{
    long int n=10000;
    int it=0;
    double tim3[10];

    printf("A_size,selction\n");

    FILE *fp = fopen("data.txt","w");

    while(it++ < 10)
    {
        long int c[n];

        for(long int i=0;i<n;i++)
        {
            long int no=rand()%n+1;
            c[i]=no;
        }

        clock_t start,end;

        start=clock();
        selection(c,n);
        end=clock();

        tim3[it-1]=((double)(end-start))/CLOCKS_PER_SEC*10000;
        
        fprintf(fp, "%li,%lims\n",n,(long int)tim3[it-1]);

        printf("%li,%lims\n",n,(long int)tim3[it-1]);

        n += 10000;
    }
    fclose(fp);
    return 0;
}