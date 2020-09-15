#include <stdio.h>
#include <stdlib.h>

// 입력받은 스도쿠 map
int map[9][9];
// 0의 갯수
int n;
typedef struct 
{
    int row;
    int col;
} ANSWER;
// 인덱스 저장
ANSWER an[81];

void print_map()
{
    int an_index = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int check(int count, int num)
{
    int row = an[count].row;
    int col = an[count].col;

    //printf("%d %d %d\n", row, col, answer);
    // 행, 열에 같은 숫자가 있을 경우
    for(int i = 0; i < 9; i++)
    {
        if(map[row][i] == num)
            return 0;
        if(map[i][col] == num)
            return 0;
    }

    // 포함된 사각형에 같은 숫자가 있는 경우
    int r = row / 3; int c = col / 3;
    r *= 3; c *= 3;
    for(int i = 0; i < 3; i++)
    {
        for(int  j = 0; j < 3; j++)
        {
            if (map[r + i][c + j] == num)
                return 0;
        }
    }
    return 1;
}

void back(int count)
{
    // 탈출 조건
    if (count == n)
    {
        print_map();
        exit(0);
    }

    for(int i = 1; i <= 9; i++)
    {
        // 현재 위치에 숫자i가 유효한가 검사
        if(check(count, i))
        {
            int row = an[count].row;
            int col = an[count].col;
            map[row][col] = i;
            back(count + 1);
            // 다시 되돌아 온 경우(백트랙) 0으로 초기화 후
            // i + 1부터 다시 검사한다
            map[row][col] = 0;
        }
    }
}

int main(void)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
            {
                an[n].row = i;
                an[n].col = j;
                n++;
            }
        }
    }

    back(0);
}