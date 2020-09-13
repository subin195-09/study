#include <stdio.h>
#include <string.h>

// 괄호를 저장
char stack[100];
int pos;

void push(char c) {stack[pos++] = c;}

char top() {return pos == 0 ? '\0' : stack[pos - 1];}

int pop()
{
    if (pos == 0) return 1;
    else
    {
        stack[--pos] = '\0';
        return 0;
    }
}

void init_stack(void)
{
    while(pos != 0)
        pop();
}

char *check(char *s)
{
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '(' || s[i] == '[')
            push(s[i]);
        else if(s[i] == ')')
        {
            if (top() != '(')
                return "no";
            else
                pop();
        }
        else if(s[i] == ']')
        {
            if (top() != '[')
                return "no";
            else
                pop();
        }
    }

    return pos == 0 ? "yes" : "no";
}

int main(void)
{
    while(1)
    {
        char string[101];
        gets(string);
        if (!strcmp(string, "."))
            break;
        printf("%s\n", check(string));
        init_stack();
    }
}