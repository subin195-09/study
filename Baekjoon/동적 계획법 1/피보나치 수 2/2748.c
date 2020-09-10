#include <stdio.h>

long fibo(int n)
{
    long fibo[90];

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= n; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    return fibo[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%ld\n", fibo(n));
}