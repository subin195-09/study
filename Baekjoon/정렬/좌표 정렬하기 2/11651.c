#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
} POINT;

int compare(const void *a, const void *b)
{
    POINT num1 = *(POINT *)a;
    POINT num2 = *(POINT *)b;

    if (num1.y < num2.y)
        return -1;
    if (num1.y > num2.y)
        return 1;
    if (num1.y == num2.y)
    {
        if(num1.x < num2.x)
            return -1;
        else if(num1.x > num2.x)
            return 1;
    }
    return 0;    
}

int main(void)
{
    int n;
    scanf("%d", &n);

    POINT p[n];
    for(int i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    
    qsort(p, n, sizeof(POINT), compare);
    
    for(int i = 0; i < n; i++)
        printf("%d %d\n", p[i].x, p[i].y);
}