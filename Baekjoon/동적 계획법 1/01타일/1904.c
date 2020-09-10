#include <stdio.h>

long tile[1000001];

long count_tile(int n)
{
    tile[1] = 1;
    tile[2] = 2;
    for(int i = 3; i <= n; i++)
        tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;
    return tile[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", count_tile(n));
}
