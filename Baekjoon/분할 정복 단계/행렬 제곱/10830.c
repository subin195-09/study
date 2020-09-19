#include <stdio.h>
#include <stdlib.h>

int n;
long long matrix[5][5];
long long result[5][5] = {1};
long long temp[5][5];

void matrix_mul(long long mat1[5][5], long long mat2[5][5])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < n; k++)
                temp[i][j] += mat1[i][k] * mat2[k][j];
            temp[i][j] %= 1000;
        }           
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            mat1[i][j] = temp[i][j];
    }
}

void ft_pow(long long b)
{
    while(b > 0)
    {
        if(b % 2 == 1)
            matrix_mul(result, matrix);
        matrix_mul(matrix, matrix);
        b /= 2;
    }
}

int main(void)
{
    long long b;
    scanf("%d %lld", &n, &b);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%lld", &matrix[i][j]);
        result[i][i] = 1;
    }

    ft_pow(b);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%lld ", result[i][j]);
        printf("\n");
    }
}