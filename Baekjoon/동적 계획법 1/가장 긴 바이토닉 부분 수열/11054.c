#include <stdio.h>

int num[1001];

// {num[1], ... , num[i]} 까지 최대 증가 부분 수열
int sub_right[1001];
// {num[i], ... , num[1]} 까지 최대 증가 부분 수열
int sub_left[1001];

// sub_right[i] + sub_left[i] 가 최대가 되는 수열을 구한다
int max(int a, int b) {return a > b ? a : b;}

int bitonic(int n)
{
    int result = 1;

    // sub_right 구하기
    for(int i = 1; i <= n; i++)
    {
        sub_right[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if (num[j] < num[i])
                sub_right[i] = max(sub_right[i], sub_right[j] + 1);
        }
    }

    // sub_left 구하기
    for(int i = n; i >= 1; i--)
    {
        sub_left[i] = 1;
        for(int j = n; j >= i; j--)
        {
            if (num[j] < num[i])
                sub_left[i] = max(sub_left[i], sub_left[j] + 1);
        }
    }

    // sub_right + sub_left의 최대값 구하기
    for(int i = 1; i <= n; i++)
        result = max(result, sub_right[i] + sub_left[i]);

    return result - 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);

    printf("%d\n", bitonic(n));
}