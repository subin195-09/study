#include <stdio.h>

int num[10000];

void swap(int i, int j)
{
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

// 선택정렬
void selection_sort(int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(num[i] > num[j])
                swap(i, j);
        }
    }
}

// 삽입 정렬
void insertion_sort(int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(num[j] > num[j + 1])
                swap(j, j + 1);
        }
    }
}

// 거품 정렬
void bubble_sort(int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(num[j] > num[j + 1])
                swap(j, j + 1);
        }
    }
}

// 시간복잡도 O(n * n) 정렬
int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    //selection_sort(n);
    //insertion_sort(n);
    bubble_sort(n);

    for(int i = 0; i < n; i++)
        printf("%d\n", num[i]);
}