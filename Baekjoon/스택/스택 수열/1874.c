#include <stdio.h>

int stack[100001];
// record는 최대 20만개까지 나올 수 있음!
char record[200001];
int arr[100000];
int pos;
int record_index;
int num = 1;

void push() {stack[pos++] = num;}
int top() {return pos == 0 ? 0 : stack[pos - 1];}
int pop()
{
    if(pos == 0) return 0;
    else
    {
        stack[--pos] = 0;
        return 1;
    }
}

int sequence(int input)
{
    while (top() < input)
    {
        push();
        num++;
        record[record_index++] = '+';
    }
    if (top() == input)
    {
        if (!pop())
            return 0;
        record[record_index++] = '-';
        return 1;
    }
    else
        return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for(int i = 0; i < n; i++)
    {
        if(!sequence(arr[i]))
        {
            printf("NO\n");
            return 0;
        }
    }
    
    for(int i = 0; i < record_index; i++)
        printf("%c\n", record[i]);
}