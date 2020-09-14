#include <stdio.h>
#include <stdlib.h>

struct people {
    int w;
    int h;
    int result;
};

struct people p[50];

void grade_people(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (p[i].w < p[j].w && p[i].h < p[j].h)
                p[i].result++;
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", p[i].result + 1);
    printf("\n");
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].w, &p[i].h);
    }
    
    grade_people(n);
}