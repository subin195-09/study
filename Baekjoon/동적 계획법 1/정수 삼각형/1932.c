#include <stdio.h>

// 입력받은 삼각형
int triangle[501][501];
// 선택된 길을 계산하여 저장
int sel[501][501];

int max(int a, int b) {return a > b ? a : b;}

int find_max(int n)
{
    int max_size = 0;
    // 현재의 값이 최대가 되는 부모 노드를 계산
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            sel[i][j] = max(sel[i - 1][j - 1], sel[i - 1][j]) + triangle[i][j];
    }

    // 삼각형의 맨 밑부분까지 왔을 때
    // 길이가 최대인 값을 리턴 해준다
    for(int i = 1; i <= n; i++)
    {
        if (max_size < sel[n][i])
            max_size = sel[n][i];
    }

    return max_size;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            scanf("%d", &triangle[i][j]);
    }

    printf("%d\n", find_max(n));
}