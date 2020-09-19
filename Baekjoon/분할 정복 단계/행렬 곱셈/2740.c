#include <stdio.h>

int a[100][100];
int b[100][100];
int result[100][100];

void matrix_mul(int N, int M, int K)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            for(int k = 0; k < M; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

// 슈트라센 알고리즘을 쓰면 (단 행렬의 크기가 2^n 이어야함)
// 행렬곱셈의 시간복잡도를 줄일 수 있다
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }

    int k;
    scanf("%d %d", &m, &k);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
            scanf("%d", &b[i][j]);
    }

    matrix_mul(n, m, k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}