#include <stdio.h>

#include <stdio.h>

long pado[101];

void padovan()
{
    pado[1] = 1;
    pado[2] = 1;
    pado[3] = 1;
    pado[4] = 2;
    for(int i = 5; i <= 100; i++)
        pado[i] = pado[i - 2] + pado[i - 3];
}

int main(void)
{
    padovan();
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%ld\n", pado[n]);
    }
}

