#include <stdio.h>

int paper[128][128];
int white;
int blue;

int what_color(int s_row, int s_col, int size)
{
    int color = paper[s_row][s_col];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(paper[s_row + i][s_col + j] != color)
                return -1;
        }
    }
    return color;
}

void cut(int s_row, int s_col, int size)
{
    int color = what_color(s_row, s_col, size);
    //printf("%d %d %d %d\n", s_row, s_col, size, color);
    if (color < 0 && (size / 2) >= 1)
    {
        int div_size = size / 2;
        cut(s_row, s_col, div_size);
        cut(s_row + div_size, s_col, div_size);
        cut(s_row, s_col + div_size, div_size);
        cut(s_row + div_size, s_col + div_size, div_size);
    }
    else if (color == 0)
        white++;
    else if (color == 1)
        blue++;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &paper[i][j]);
    }

    cut(0, 0, n);

    printf("%d\n", white);
    printf("%d\n", blue);
}