#include <stdio.h>
#include <stdlib.h>

int num[10];

int put_arr(int n)
{
    int i = 0;
    while(n > 0)
    {
        num[i++] = n % 10;
        n /= 10;
    }
    return i;
}

void swap(int i, int j)
{
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

void sort_inside(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
            if (num[i] < num[j])
                swap(i, j);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    if(n == 0)
    {
        printf("0\n");
        exit(0);
    }

    int size = put_arr(n);
    sort_inside(size);
    for(int i = 0; i < size; i++)
        printf("%d", num[i]);
    printf("\n");
}