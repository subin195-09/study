#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
} POINT;

int min(int a, int b) {return a > b ? b : a;}

int get_dis(POINT p1, POINT p2)
{
    int width = p2.x - p1.x;
    int height = p2.y - p1.y;
    return width * width + height * height;
}

int compare_x(const void *a, const void *b)
{
    POINT p1 = *(POINT *)a;
    POINT p2 = *(POINT *)b;

    if (p1.x < p2.x)
        return -1;
    else if(p1.x > p2.x)
        return 1;
    else
        return 0;
}

int compare_y(const void *a, const void *b)
{
    POINT p1 = *(POINT *)a;
    POINT p2 = *(POINT *)b;

    if (p1.y < p2.y)
        return -1;
    else if(p1.y > p2.y)
        return 1;
    else
        return 0;
}

int find_distance(POINT *p, int start, int end)
{
    int result = 1000000000;
    // 만약 점이 3개 이하 일때
    // 브루트 포스 알고리즘 사용
    if(start - end + 1 == 2)
        return min(result, get_dis(p[start], p[end]));
    else if (start - end + 1 == 3)
    {
        result = min(result, get_dis(p[start], p[start + 1]));
        result = min(result, get_dis(p[start], p[end]));
        return min(result, get_dis(p[start + 1], p[end]));
    }

    // 중간점을 기준으로 제일 짧은 거리에 있는 점을 선택
    int mid = start + end / 2;
    int left = find_distance(p, start, mid);
    int right = find_distance(p, mid + 1, end);
    result = min(left, right);
    
    // mid 의 x축 기준으로 result보다 작은 점들을 저장한다
    int start_count = -1;
    int count = 0;
    for(int i = start; i <= end; i++)
    {
        int x_dist = p[i].x - p[mid].x;
        if (x_dist * x_dist < result)
        {
            if (start_count < 0)
                start_count = i;
            count++;
        }
    }
    POINT temp[count];
    for(int i = 0; i < count; i++)
        temp[i] = p[start_count + i];

    // 저장된 점들을 y축을 기준으로 정렬 후
    // result보다 가까운 거리에 있는 점을 update해준다
    qsort(temp, count, sizeof(POINT), compare_y);
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            int y_dis = temp[j].y - temp[i].y;
            if (y_dis * y_dis < result)
            {
                int update_dis = get_dis(temp[i], temp[j]);
                if(update_dis < result)
                    result = update_dis;
            }
            else
                break;
        }
    }
    return result;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    POINT p[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    
    // x좌표 기준으로 정렬
    qsort(p, n, sizeof(POINT), compare_x);

    printf("%d\n", find_distance(p, 0, n - 1));
}