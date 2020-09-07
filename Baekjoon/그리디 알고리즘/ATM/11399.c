#include <stdio.h>
#include <stdlib.h>

int people;
int *time;

// end - 1번째 까지의 합을 구해줌
int cal_sum(int end)
{
    int result = 0;
    for (int i = 0; i < end; i++)
        result += time[i];
    return result;
}

// 시간을 오름차순으로 정렬
int static compare(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return -1;
    
    if (*(int *)a > *(int *)b)
        return 1;

    return 0;
}

int main(void)
{
    int result = 0;
    scanf("%d", &people);

    if(!(time = (int *)malloc(sizeof(int) * people)))
        return 0;
    
    for (int i = 0; i < people; i++)
        scanf("%d", &time[i]);
    
    qsort(time, people, sizeof(int), compare);

    for (int i = 1; i <= people; i++)
        result += cal_sum(i);
    
    printf("%d\n",result);
}