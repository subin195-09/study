#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int age;
    char name[101];
} MEMBER;

int compare(const void *a, const void *b)
{
    MEMBER mem1 = *(MEMBER *)a;
    MEMBER mem2 = *(MEMBER *)b;

    if (mem1.age <= mem2.age)
        return -1;
    else
        return 1;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    MEMBER m[n];
    for(int i = 0; i < n; i++)
        scanf("%d %s", &m[i].age, m[i].name);
    
    qsort(m, n, sizeof(MEMBER), compare);

    for(int i = 0; i < n; i++)
        printf("%d %s\n", m[i].age, m[i].name);
}