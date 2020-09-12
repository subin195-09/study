#include <stdio.h>
#include <stdlib.h>

int num[101][2];

int max(int a, int b) {return a > b ? a : b;}

int lis(int n, int pivot)
{
    int result = 1;
    int sub[n + 1];
    for(int i = 1; i <= n; i++)
    {
        sub[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if(num[j][pivot] < num[i][pivot])
            {
                sub[i] = max(sub[i], sub[j] + 1);
                result = max(result, sub[i]);
            }
        }
    }
    return result;
}

int static compare(const void *first, const void *second)
{
    int num1 = *(int *)first;
    int num2 = *(int *)second;

    if (num1 > num2)
        return 1;
    if (num1 < num2)
        return -1;
    else
        return 0;
}

// 1) A전봇대를 오름차순 정렬
// 2) B전봇대의 LIS를 구한다
int electric(int n)
{
    int result;

    // A전봇대순으로 정렬
    qsort(num, n + 1, sizeof(int *), compare);

    for(int i = 1; i <= n; i++)
        printf("%d %d\n", num[0][i], num[1][i]);
    printf("\n");
    // B전봇대대 lis
    result = lis(n, 1);
    printf("%d", result);

    return n - result;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d", &num[i][0], &num[i][1]);

    printf("%d\n", electric(n));
}