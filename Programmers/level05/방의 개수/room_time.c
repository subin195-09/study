#include <stdio.h>
#include <stdlib.h>

// 방향 정보
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

typedef struct {
    double x;
    double y;
} POINT;

typedef struct {
    POINT start;
    POINT end;
    POINT mid;
} LINE;

LINE line[100001];
double x, y, next_x, next_y;

int solution(int arrows[], size_t arrows_m) {
    int answer = 0;

    for(int i = 0; i < arrows_m; i++)
    {
        x = next_x;
        y = next_y;
        next_x += dx[arrows[i]];
        next_y += dy[arrows[i]];

        //printf("(%f, %f) -> (%f, %f)\n", x, y, next_x, next_y);
        // arrows[i]대로 그려진 line 표시
        line[i + 1].start.x = x;
        line[i + 1].start.y = y;
        line[i + 1].end.x = next_x;
        line[i + 1].end.y = next_y;
        line[i + 1].mid.x = (x + next_x) / 2;
        line[i + 1].mid.y = (y + next_y) / 2;

        // 현재까지 그려진 line
        //answer += check_room(i);
        
        int route = 0;
        int cross = 0;

        // 방이 생기는 경우
        // 1) 길이 X자로 교차된 경우 (cross)
        // 2) 지나온 적 없는 길이고, 방문했던 노드일 경우 (route)
        for(int j = 0; j <= i; j++)
        {
            // 길이 X자로 교차된 경우
            if(line[j].mid.x == (x + next_x) / 2 && line[j].mid.y == (y + next_y) / 2)
                cross = 1;
        
            // 중복된 길일 경우 (길은 양방향 이므로 둘다 검사)
            if (line[j].start.x == x && line[j].start.y == y && line[j].end.x == next_x && line[j].end.y == next_y)
            {
                cross = 0;
                route = 0;
                break;
            }
            else if (line[j].start.x == next_x && line[j].start.y == next_y && line[j].end.x == x && line[j].end.y == y)
            {
                cross = 0;
                route = 0;
                break;
            }

            // 지나본 적 없는 길이고, 방문했던 노드일 경우
            else if(line[j].end.x == next_x && line[j].end.y == next_y)
                route = 1;
        }
        answer += cross + route;
        //printf("%d\n", answer);
    }
        
    return answer;
}

int main(void)
{
    int num[19] = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
    // 정답 : 3
    printf("%d\n", solution(num, 19));
}