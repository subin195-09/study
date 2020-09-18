#include <stdio.h>

char result[10000];
char map[65][65];
int r_index;

char what_number(int row, int col, int size)
{
    char number = map[row][col];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(map[row + i][col + j] != number)
                return -1;
        }
    }
    return number;
}

void zip(int row, int col, int size)
{
    char number = what_number(row, col, size);
    //printf("%d %d %d %c\n", row, col, size, number);
    if(number < 0 && (size / 2) >= 1)
    {
        result[r_index++] = '(';
        int div_size = size / 2;
        zip(row, col, div_size);
        zip(row, col + div_size, div_size);
        zip(row + div_size, col, div_size);
        zip(row + div_size, col + div_size, div_size);
        result[r_index++] = ')';
    }
    else
        result[r_index++] = number;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%s", map[i]);

    zip(0, 0, n);
    printf("%s\n", result);
}