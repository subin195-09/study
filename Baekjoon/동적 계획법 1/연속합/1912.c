#include <stdio.h>
#include <stdlib.h>

int num[100001];
int sum[100001];

int max(int a, int b) {return a > b ? a : b;}

// sum[i] : sum[i -1]까지의 최대 연속합 + num[i], num[i] 중의 최댓값을 구한다
// 풀이 : 출력해보면서 확인해볼 것
int max_sum(int n)
{
    int result = -1000;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = max(num[i], sum[i - 1] + num[i]);
        //printf("%d ", sum[i]);
        result = max(result, sum[i]);
    }
    //printf("\n");
    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        sum[i] = -1000;
    }
    
    printf("%d\n", max_sum(n));
}