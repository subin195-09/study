#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;
char **map;

void init_map(void)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            map[i][j] = ' ';
    }
}

void draw_star(int i, int j, int num)
{
    if (num == 1)
    {
        map[i][j] = '*';
        return;
    }

    int m = num / 3;
    int cnt = 0;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            cnt++;
            if (cnt != 5)
                draw_star(i + a*m, j + b*m, m);
        }
    }
}

void print_map()
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

int main(void)
{
    scanf("%d", &num);
    
    // map 할당
    map = (char **)malloc(sizeof(char *) * num);
    for (int i = 0; i < num; i++)
    {
        if (!(map[i] = (char *)malloc(sizeof(char) * num)))
            return 0;
    }

    // map을 빈문자로 초기화 해준다
    init_map();

    // 필요한 부분을 '*'로 채워준다
    draw_star(0, 0, num);

    print_map(num);
}