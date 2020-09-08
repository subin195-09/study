#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// check[현 x][현 y][후 x][후 y]
int check[11][11][11][11];

// 길을 양방향으로 체크해준다
int node_check(char *dirs, int size)
{
    int x = 5;
    int y = 5;
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        if (dirs[i] == 'U' && y < 10)
        {
            if (!check[x][y][x][y + 1])
            {
                check[x][y][x][y + 1] = 1;
                check[x][y + 1][x][y] = 1;
                count++;
            }
            y++;
        }
        if (dirs[i] == 'D' && y > 0)
        {
            if (!check[x][y][x][y - 1])
            {
                check[x][y][x][y - 1] = 1;
                check[x][y - 1][x][y] = 1;
                count++;
            }
            y--;
        }
        if (dirs[i] == 'R' && x < 10)
        {
            if (!check[x][y][x + 1][y])
            {
                check[x][y][x + 1][y] = 1;
                check[x + 1][y][x][y] = 1;
                count++;
            }
            x++;
        }
        if (dirs[i] == 'L' && x > 0)
        {
            if (!check[x][y][x - 1][y])
            {
                check[x][y][x - 1][y] = 1;
                check[x - 1][y][x][y] = 1;
                count++;
            }
            x--;
        }
    }
    return count;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    int answer = 0;
    int size = strlen(dirs);
    
    answer = node_check(dirs, size);
    
    return answer;
}