#include <stdio.h>

// 0 : R, 1 : G, 2 : B
int cost[1001][3];
int sel[1001][3];

int min(int a, int b){ return a > b ? b : a;}

int color_house(int n)
{
    for(int i = 1; i <= n; i++)
    {
        // i번째 빨간색을 칠했을 때 최솟값
        sel[i][0] = cost[i][0] + min(sel[i - 1][1], sel[i - 1][2]);
        // i번재 초록색을 칠했을 때 최솟값
        sel[i][1] = cost[i][1] + min(sel[i -1][0], sel[i - 1][2]);
        // i번째 파란색을 칠했을 때 최솟값
        sel[i][2] = cost[i][2] + min(sel[i - 1][0], sel[i - 1][1]);
    }

    return min(min(sel[n][0], sel[n][1]), sel[n][2]);
}

int main(void)
{
    // 집의 갯수
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    
    printf("%d\n", color_house(n));
}