#include <stdio.h>
#include <stdlib.h>

int num[11];
// +, -, x, /
int operation[4];
int n;
int result_min = 1000000000;
int result_max = -1000000000;

int min(int a, int b) {return a > b ? b : a;}
int max(int a, int b) {return a > b ? a : b;}

void dfs(int count, int plus, int minus, int mul, int div, int result)
{
    // 모든 연산자를 다 사용한 경우
    if (count == n)
    {
        result_min = min(result, result_min);
        result_max = max(result, result_max);
    }

    if (plus > 0)
    {
        //printf("%d + %d = %d\n", result, num[count], result + num[count]);
        dfs(count + 1, plus - 1, minus, mul, div, result + num[count]);
    }
    if (minus > 0)
    {
        //printf("%d - %d = %d\n", result, num[count], result - num[count]);
        dfs(count + 1, plus, minus - 1, mul, div, result - num[count]);
    }
    if (mul > 0)
    {
        //printf("%d * %d = %d\n", result, num[count], result * num[count]);
        dfs(count + 1, plus, minus, mul - 1, div, result * num[count]);
    }
    if (div > 0)
    {
        //printf("%d / %d = %d\n", result, num[count], result / num[count]);
        dfs(count + 1, plus, minus, mul, div - 1, result / num[count]);
    }
}

int main(void)
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    for(int i = 0; i < 4; i++)
        scanf("%d", &operation[i]);

    dfs(1, operation[0], operation[1], operation[2], operation[3], num[0]);

    printf("%d\n", result_max);
    printf("%d\n", result_min);
}