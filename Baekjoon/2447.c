#include <stdio.h>
#include <string.h>

void init_map(char *map[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
            map[i][j] = ' ';
    }
}

void draw_star(char *map[], int num, char *star)
{
    int len = strlen(star);
    for (int i = 0; i < num; i += len)
    {
        for (int j = 0; j < num; j += len)
        {
            if (((i + 1) % 3 == 0) || ((j + 1) % 3 == 0))
                map[i][j] = star;
        }
    }

}

void print_map(char *map[], int num)
{
    for (int i = 0; i < num; i++)
        printf("%s\n", map[i]);
}

int main(void)
{
    int num;
    char **map;

    scanf("%d", &num);
    init_map(map, num);
    draw_star(map, num, "*");
    print_map(map, num);
}