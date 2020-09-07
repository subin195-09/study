#include <stdio.h>
#include <stdlib.h>

// n 종류의 동전으로 합 k를 만든다
int n;
int k;
// 동전의 종류
int *coin;

int greedy(void)
{
    int count = 0;
    int select = 0;
    int i = n - 1;
    while (select != k)
    {
        select += coin[i];
        
        if (select > k)
            select -= coin[i--];
        else
            count++;
    }
    return count;
}

int main(void)
{
    scanf("%d %d", &n, &k);

    if(!(coin = (int *)malloc(sizeof(int) * n)))
        return 0;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    
    printf("%d\n", greedy());
}