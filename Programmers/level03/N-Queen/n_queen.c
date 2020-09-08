#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

char *chess;
int answer;
int size;

int check(int i)
{
    // 같은 열이거나, 대각선인지 체크
    for(int j = 0; j < i; j++)
    {
        if (chess[j] == chess[i])
            return 0;
        if (abs(chess[i] - chess[j]) == (i - j))
            return 0;
    }
    return 1;
}

void queen(int i)
{
    if (!check(i))
        return ;
    if (i == size - 1)
        answer++;
    else
    {
        for(int j = 0; j < size; j++)
        {
            chess[i + 1] = j;
            queen(i + 1);
        }
    }
}

int solution(int n) {
    
    size = n;
    
    if(!(chess = malloc(sizeof(int) * n)))
        return 0;
    
    for (int i = 0; i < n; i++)
    {
        chess[0] = i;
        queen(0);
    }
    
    return answer;
}