#include <stdio.h>
#include <stdlib.h>

int n, m;
// 정답을 저장시킬 배열
int *arr;
// 1 ~ n 중에서 뽑힌 숫자를 check하는 배열
int *check;

void dfs_basic(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if(check[i])
        {
            arr[count] = i + 1;
            check[i] = 0;
            dfs_basic(count + 1);
            check[i] = 1;
        }
    }
}

int main(void)
{
    // 1 ~ n 까지 m개의 수를 뽑는 경우
    scanf("%d %d", &n, &m);
    
    arr = malloc(sizeof(int) * m);
    check = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        check[i] = 1;
    dfs_basic(0);
}