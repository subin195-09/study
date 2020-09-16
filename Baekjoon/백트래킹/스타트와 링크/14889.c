#include <stdio.h>
#include <stdlib.h>

int people[20][20];
int visited[20];
int n;
int result = 100;

int min(int a, int b) {return a > b ? b : a;}

// N과 M(2) 응용
void dfs(int count, int i_index)
{
    if(count == n / 2)
    {
        int start = 0;
        int link = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i] && visited[j])
                    start += people[i][j];
                else if (!visited[i] && !visited[j])
                    link += people[i][j];
            }   
        }
        //printf("%d\n", abs(start - link));
        result = min(result, abs(start - link));
        return ;
    }
    for(int i = i_index; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            dfs(count + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &people[i][j]);
    }

    dfs(0, 0);
    printf("%d\n", result);
}