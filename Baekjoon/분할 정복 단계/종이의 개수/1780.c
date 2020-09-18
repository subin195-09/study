#include <stdio.h>

int map[2187][2187];
int count[3];

int what_number(int row, int col, int size)
{
    int number = map[row][col] + 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(number != map[row + i][col + j] + 1)
                return -1;
        }
    }
    return number;
}

int cut(int row, int col, int size)
{
    int number = what_number(row, col, size);
    //printf("%d %d %d %d\n", row, col, size, number);
    if(number < 0 && (size / 3) >= 1)
    {
        int d_size = size / 3;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
                cut(row + d_size * i, col + d_size * j, d_size);
        }
    }
    else
        count[number]++;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    }

    cut(0, 0, n);
    for(int i = 0; i < 3; i++)
        printf("%d\n", count[i]);
}