#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 방향 정보
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(int arrows[], size_t arrows_m) {
    int answer = 0;
    int x = arrows_m / 2;
    int y = arrows_m / 2;
    // 방문 체크 (음수가 나오지 않도록 최댓값 *2 )
    int visited_path[arrows_m * 2 + 1][arrows_m * 2 + 1][arrows_m * 2 + 1][arrows_m * 2 + 1];
    int visited_node[arrows_m * 2 + 1][arrows_m * 2 + 1];
    
    visited_node[x][y] = 1;
    for(int i = 0; i < arrows_m; i++)
    {
        for(int j = 0; j < arrows_m ; j++)
        {
            int xpos = x + dx[arrows[i]];
            int ypos = y + dy[arrows[i]];
            
            // 다음 좌표가 이전에 방문한 적이 있고
            // 이동한 적이 없는 경로하면 방을 만든다
            if(visited_node[xpos][ypos] && !(visited_path[x][y][xpos][ypos]))
                answer++;
            
            visited_path[x][y][xpos][ypos] = 1;
            visited_path[xpos][ypos][x][y] = 1;
            visited_node[xpos][ypos] = 1;
            x = xpos;
            y = ypos;
        }
    }
    
    return answer;
}