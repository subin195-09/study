#include <stdio.h>

int wine[10001];
int sel[10001];

int max(int a, int b) {return a > b ? a : b;}

// 게단 오르기(2579.c)와 비슷한 문제
// 단, 꼭 마지막 와인(계단)을 마실 필요가 없으므로
// 마지막 와인을 마시는 것과, 마시지 않은 것 중 최대값을 구하여 저장
int drink_wine(int n)
{
    sel[1] = wine[1];
    sel[2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++)
    {
        sel[i] = max(sel[i - 2], sel[i - 3] + wine[i - 1]) + wine[i];
        sel[i] = max(sel[i -1], sel[i]);
    }
    
    return max(sel[n], sel[n -1]);
}

int main(void)
{
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &wine[i]);
    
    printf("%d\n", drink_wine(n));
}