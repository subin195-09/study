#include <stdio.h>

int card[100];
int sum[100];
int check[100];
int N, M;
int sum_max;

int max(int a, int b) {return a > b ? a : b;}

void black_jack(int count)
{
    if(count == 3)
    {
        int temp_sum = 0;
        for(int i = 0; i < count; i++)
            temp_sum += sum[i];
        if (temp_sum <= M)
            sum_max = max(sum_max, temp_sum);
        return ;
    }
    for(int i = 0; i < N; i++)
    {
        if (check[i])
        {
            sum[count] = card[i];
            check[i] = 0;
            black_jack(count + 1);
            check[i] = 1;
        }
    }
}

int main(void)
{
    // N개의 카드, 최대 합 M
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    for(int i = 0; i < N; i++)
        check[i] = 1;

    black_jack(0);
    printf("%d\n", sum_max);
}