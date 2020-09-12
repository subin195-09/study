#include <stdio.h>

// 입력받은 수열
int num[1001];

// {num[1], num[2], ... , num[i]} 에서 최대길이 부분 수열
int sub[1001];

int max(int a, int b) {return a > b ? a : b;}

int longest(int n)
{
    int result = 1;

    for(int i = 1; i <= n; i++)
    {
        sub[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if (num[j] < num[i])
            {
                // num[j]까지의 최대 부분수열 에서
                // num[i]를 추가하여 부분수열의 길이를 구한다
                sub[i] = max(sub[i], sub[j] + 1);
                result = max(result, sub[i]);
            }
        }
    }

    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    
    printf("%d\n", longest(n));
}