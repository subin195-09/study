#include <stdio.h>

int seperated_sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int get_m(int n)
{
    for(int i = 1; i != n; i++)
    {
        if (n == i + seperated_sum(i))
            return i;
    }
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", get_m(n));
}