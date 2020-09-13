#include <stdio.h>

long stack[100000];
int pos = 0;
int sum;

void pop(void)
{
    if (pos == 0)
        return ;
    else
    {
        sum -= stack[pos - 1];
        stack[--pos] = 0;
    }
}

void push(int num)
{
    sum += num;
    stack[pos++] = num;
}

int main(void)
{
    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; i++)
    {
        int num;
        scanf("%d", &num);

        if (num == 0)
            pop();
        else
            push(num);
    }

    printf("%d\n", sum);
}