#include <stdio.h>
#include <stdlib.h>

// 인덱스(i) : 행
// chess[i] : i번째 행의 열
// count : 완성된 체스판을 세준다
int *chess;
int count;
int n;

// i번째 행에 있는 값이 유효한지 확인해주는 함수
int check(int i)
{
    // 같은 행일 경우는 없으므로
    // 같은 열인지, 대각선으로 겹치는지 체크
    for (int j = 0; j < i; j++)
    {
        // 같은 열에 있는지 체크
        if (chess[j] == chess[i])
            return 0;
        
        // 같은 대각선 상에 놓여 있는지 체크
        if (abs(chess[i] - chess[j]) == (i - j))
            return 0;
    }
    return 1;
}

void queen(int i)
{
    // i번째에 놓아도 되는지 check
    // 백트랙킹 : 가능성이 없는 가지를 쳐낸다
    if (!check(i))
        return ;

    // n번째 까지 다 채웠을 때 count 증가
    if (i == n - 1)
        count++;
    else
    {
        for (int j = 0; j < n; j++)
        {
            chess[i + 1] = j;
            queen(i + 1);
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    if (!(chess = malloc(sizeof(int) * n)))
        return 0;

    // 첫번째 행에 말을 하나씩 놓고 탐색
    for(int i = 0; i < n; i++)
    {
        chess[0] = i;
        queen(0);
    }
    printf("%d\n", count);
}