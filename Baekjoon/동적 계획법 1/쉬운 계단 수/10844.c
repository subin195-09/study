#include <stdio.h>
#include <stdlib.h>

// num[i][j] : (i + 1)번째 자리수에 j 가 올 수 있는 경우의 수
// num[i][j] = num[i - 1][j - 1] + num[i - 1][j + 1] (단, j가 0일때는 j + 1만, j가 9일 때는 왼쪽만)
// num[i]의 모든 수를 더하면 길이가 (i + 1)인 계단 수의 갯수이다.
int stair_num(long num[][10], int n)
{
    long result = 0;
    int mod_num = 1000000000;

    num[0][0] = 0;
    for(int i = 1; i < 10; i++)
        num[0][i] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (j == 0) {num[i][j] = num[i - 1][j + 1] % mod_num;}
            else if (j == 9) {num[i][j] = num[i - 1][j - 1] % mod_num;}
            else {num[i][j] = (num[i - 1][j - 1] + num[i - 1][j + 1]) % mod_num;}
        }
    }

    for(int i = 0; i < 10; i++)
        result += num[n - 1][i];

    return result % mod_num;
}
int main(void)
{
    int n;

    scanf("%d", &n);

    long num[n][10];

    printf("%d\n", stair_num(num, n));   
}