#include <stdio.h>

char chess[51][51];

char white[8][9] =
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

char black[8][9] =
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int min(int a, int b) {return a > b ? b : a;}

int check_black(int row, int col)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(chess[row + i][col + j] != black[i][j])
                count++;
        }
    }
    return count;
}

int check_white(int row, int col)
{
    int count = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(chess[row + i][col + j] != white[i][j])
                count++;
        }
    }
    return count;
}

int color_chess(int n, int m)
{
    int result = 80;

    for(int i = 0; i < n - 7; i++)
    {
        for(int j = 0; j < m - 7; j++)
        {
            int temp;
            temp = check_black(i, j);
            temp = min(temp, check_white(i, j));
            result = min(result, temp);
        }
    }
    return result;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%s", chess[i]);
    
    printf("%d\n", color_chess(n, m));
}