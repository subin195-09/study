#include <stdio.h>
#include <stdlib.h>

int weight[101];
int value[101];

// my[물건 수][무게]
// my[n][k] : n번째 물건, k무게까지 고려했을 떄 최대 가치
int my[101][100001];

int max(int a, int b) {return a > b ? a : b;}

// 1) 물건을 담는 경우
// 2) 물건을 담지 않는 경우
int knapsack_problem(int n, int k)
{
    for(int i = 1; i <= n; i++)
    {
        // i번째 물건을 j무게까지 고려했을 때
        for(int j = 1; j <= k; j++)
        {
            // max(i번째 물건을 담지 않을 경우, 담을 경우)
            if(j >= weight[i])
                my[i][j] = max(my[i - 1][j], my[i - 1][j - weight[i]] + value[i]);
            else
                my[i][j] = my[i - 1][j];
        }
    }
    return my[n][k];
}

int main(void)
{
    // 물품의 수
    int n;
    // 최대 무게
    int k;

    scanf("%d %d", &n, &k);
    
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &weight[i], &value[i]);
    
    printf("%d\n", knapsack_problem(n, k));
}