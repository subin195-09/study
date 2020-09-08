#include <stdio.h>
#include <stdlib.h>

int n, m;
// 정답을 저장시킬 배열
int *arr;
// 1 ~ n 중에서 뽑힌 숫자를 check하는 배열
int *check;

// 현재 index의 정보를 같이 넘겨 그 전의 
// index는 선택하지 않도록 한다
void dfs_basic(int index, int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");

        return ;
    }
    for (int i = index; i < n; i++)
    {
        if(check[i])
        {
            arr[count] = i + 1;
            check[i] = 0;
            dfs_basic(i + 1, count + 1);
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
    dfs_basic(0, 0);
}