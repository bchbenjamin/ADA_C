#include <stdio.h>
#include <time.h>

int main() 
{
    int a00, a01, a10, a11;
    int b00, b01, b10, b11;

    int m1, m2, m3, m4, m5, m6, m7;
    int c00, c01, c10, c11;

    clock_t start, end;
    double cpu_time;
    // Start time
    start = clock();

    printf("Enter Matrix A (2x2):\n");
    scanf("%d %d %d %d", &a00, &a01, &a10, &a11);

    printf("Enter Matrix B (2x2):\n");
    scanf("%d %d %d %d", &b00, &b01, &b10, &b11);

    

    // Strassen formulas
    m1 = (a00 + a11) * (b00 + b11);
    m2 = (a10 + a11) * b00;
    m3 = a00 * (b01 - b11);
    m4 = a11 * (b10 - b00);
    m5 = (a00 + a01) * b11;
    m6 = (a10 - a00) * (b00 + b01);
    m7 = (a01 - a11) * (b10 + b11);

    // Result matrix
    c00 = m1 + m4 - m5 + m7;
    c01 = m3 + m5;
    c10 = m2 + m4;
    c11 = m1 + m3 - m2 + m6;

    // End time
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n--- Intermediate Values ---\n");
    printf("m1 = %d\n", m1);
    printf("m2 = %d\n", m2);
    printf("m3 = %d\n", m3);
    printf("m4 = %d\n", m4);
    printf("m5 = %d\n", m5);
    printf("m6 = %d\n", m6);
    printf("m7 = %d\n", m7);

    printf("\n--- Result Matrix C ---\n");
    printf("%d %d\n", c00, c01);
    printf("%d %d\n", c10, c11);
    // Print theoretical complexity
    printf("\nTime Complexity: O(n^2.81)\n");


    printf("\nTime taken = %f microseconds\n", cpu_time);

    return 0;
}

