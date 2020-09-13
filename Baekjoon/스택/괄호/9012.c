#include <stdio.h>
#include <string.h>

int stack[50];
int pos;

void push() {stack[pos++] = 1;}

int pop()
{
    if(pos == 0) return 1;
    else
    {
        stack[--pos] = 0;
        return 0;
    }
}

void init_stack(void)
{
    while(pos != 0)
        pop();
}

char *check_vps(char *bracket)
{
    int size = strlen(bracket);

    if (size % 2 == 1)
        return "NO";
    
    for(int i = 0; i < size; i++)
    {
        if(bracket[i] == '(')
            push();
        else if(bracket[i] == ')')
        {
            if(pop())
                return "NO";
        }
    }

    return pos == 0 ? "YES" : "NO";
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        char bracket[51];
        scanf("%s", bracket);
        printf("%s\n", check_vps(bracket));
        init_stack();
    }
}