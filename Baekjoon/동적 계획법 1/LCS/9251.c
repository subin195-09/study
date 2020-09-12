#include <stdio.h>

char s1[1001];
char s2[1001];
int dp[1001][1001];

int max(int a, int b) {return a > b ? a : b;}

// 비교하는 위치의 문자가 같을 경우
// -> 왼쪽 대각선 값 + 1
// 비교하는 위치 문자가 다를 경우
// -> MAX(왼쪽 값, 위쪽 값)
int find_lcs(void)
{
    int i;
    int j;

    for(i = 1; s1[i]; i++)
    {
        for(j = 1; s2[j]; j++)
        {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[i- 1][j - 1];
}

int main(void)
{
    // 1번째 인덱스부터 문자열 저장
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);

    printf("%d\n", find_lcs());
}