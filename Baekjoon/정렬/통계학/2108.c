#include <stdio.h>
#include <stdlib.h>

int n;
int sum;
typedef struct
{
    int num;
    int count;
} COUNT;
COUNT c[8001];

int get_ave(void)
{
    if (sum >= 0)
        return (double)sum / n + 0.5;
    else
        return (double)sum / n - 0.5;   
}

int get_mid(int max, int min)
{
    int mid_index = 0;

    for(int i = min + 4000; i <= max + 4000; i++)
    {
        for(int j = 0; j < c[i].count; j++)
        {
            mid_index++;
            if (mid_index == n / 2 + 1)
                return i - 4000;
        }
    }
}

void swap(int i, int j)
{
    COUNT temp;
    temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

int get_mode(int max, int min)
{
    // 2번째 까지의 최빈값을 구함
    for(int i = 0; i < 2; i++)
    {
        for(int j = i + 1; j <= 8000; j++)
        {
            if(c[i].count < c[j].count)
                swap(i, j);
        }
    }

    if (c[0].count == c[1].count)
        return c[1].num;
    else
        return c[0].num;    
}

int main(void)
{
    scanf("%d", &n);

    int max = -4000;
    int min = 4000;

    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (max < temp) max = temp;
        if (min > temp) min = temp;
        sum += temp;
        c[temp + 4000].num = temp;
        c[temp + 4000].count++;
    }

    printf("%d\n", get_ave()); // 산술평균
    printf("%d\n", get_mid(max, min)); // 중앙 값
    printf("%d\n", get_mode(max, min)); // 최빈값
    printf("%d\n", max - min); // 범위
}