#include <stdio.h>
#include <stdlib.h>

// 회의 갯수
int n;
// 회의 정보 저장 구조체
struct time{
    int begin; // 시작 시간
    int end; // 끝 시간
};

int static compare(const void *a, const void *b)
{
    struct time *aa = (struct time*)a;
    struct time *bb = (struct time*)b;

    if (aa->end < bb->end)
        return -1;
    else if (aa->end > bb->end)
        return 1;
    else
    {
        if (aa->begin < bb->begin)
            return -1;
        else if(aa->begin > bb-> begin)
            return 1;
        else
            return 0;
    }
    

}

// 끝 시간이 가장 빠른 회의를 고른다.
int main(void)
{
    scanf("%d", &n);

    struct time t[n];
    for (int i= 0; i < n; i++)
        scanf("%d %d", &t[i].begin, &t[i].end);
    
    // 종료지점 기준으로 정렬
    // 종료지점이 같다면 일찍 시작지점이 빠른 순으로
    qsort(t, n, sizeof(struct time), compare);

    int count = 0;
    // 선택된 회의의 종료 시간 저장
    int temp_end = 0;

    for (int i = 0; i < n; i++)
    {
        if(t[i].begin >= temp_end)
        {
            count++;
            temp_end = t[i].end;
        }
    }

    printf("%d\n", count);
    return 0;
}