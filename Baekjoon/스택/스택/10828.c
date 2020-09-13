#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[1000];
char command[100010];

int start = -1;

int ft_atoi(char *s)
{
    int result = 0;

    for(int i = 0; s[i]; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            result = result * 10 + (s[i] - '0');
    }
    return result;
}

void execute(int n)
{
    // 정수 X를 스택에 넣는 연산이다.
    if(!strncmp(command, "push", 4))
        stack[++start] = ft_atoi(command);

     // 스택에서 가장 위에 있는 정수를 빼고 그 수 출력
    // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    else if(!strcmp(command, "pop"))
    {
        if (start < 0)
            printf("-1\n");
        else
            printf("%d\n", stack[start--]);
    }
    
    // 스택에 들어있는 정수의 개수를 출력한다.
    else if(!strcmp(command, "size"))
        printf("%d\n", start + 1);
    
    // 스택이 비어있으면 1, 아니면 0을 출력한다.
    else if(!strcmp(command, "empty"))
    {
        if(start < 0)
            printf("1\n");
        else
            printf("0\n");
    }

     // 스택의 가장 위에 있는 정수를 출력한다.
    // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    else if(!strcmp(command, "top"))
    {
        if (start < 0)
            printf("-1\n");
        else
            printf("%d\n", stack[start]);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    // 엔터를 제외한 모든 문자열을 받는다
    for(int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", command);
        execute(n);
    }
    return 0;
}