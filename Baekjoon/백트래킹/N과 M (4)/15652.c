#include <stdio.h>
#include <stdlib.h>

int n, m;
// 정답을 저장시킬 배열
int *arr;

// 선택을 표시했던 check 배열을 없애고 
// 모든 경우의 수를 출력하도록 한다
// + 현재 위치 정보를 주어 그 이후만 탐색하도록
// (2) + (3)
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
        arr[count] = i + 1;
        dfs_basic(i, count + 1);
    }
}

int main(void)
{
    // 1 ~ n 까지 m개의 수를 뽑는 경우
    scanf("%d %d", &n, &m);
    
    arr = malloc(sizeof(int) * m);

    dfs_basic(0, 0);
}