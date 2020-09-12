#include <stdio.h>
#include <stdlib.h>

struct num{
    int a;
    int b;
};

int max(int a, int b) {return a > b ? a : b;}

int static compare(const void *first, const void *second)
{
    struct num *one = (struct num*)first;
    struct num *two = (struct num*)second;

    if(one->a < two->a)
        return -1;
    else if(one->a > two ->a)
        return 1;
    else
        return 0;
}

int electric(struct num *elect, int n)
{
    int result = 1;
    int sub[n];

    for(int i = 0; i < n; i++)
    {
        sub[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(elect[j].b < elect[i].b)
            {
                sub[i] = max(sub[i], sub[j] + 1);
                result = max(result, sub[i]);
            }
        }
    }
    return n - result;
}

// 1) A전봇대를 오름차순 정렬
// 2) B전봇대의 LIS를 구한다
// 3) 전체의 전봇대 수 - (2)를 해준다
int main(void)
{
    int n;
    scanf("%d", &n);

    struct num elect[n];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &elect[i].a, &elect[i].b);
    
    // A전봇대 순으로 정렬
    qsort(elect, n, sizeof(struct num), compare);

    // B전봇대 기준으로 lis를 구해준다
    printf("%d\n", electric(elect, n));
}