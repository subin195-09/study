#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 입력받은 식
char s[300];


// - 뒤의 값들을 괄호로 묶어 더해준다

int cal_minus(int index)
{
    int sum = atoi(s);
    while(s[index] && s[index] != '-')
    {
        if (s[index] >= '0' && s[index] <= '9')
        {
           s[index] = ' '; 
        }
        else
        {
            if (s[index] == '+')
            {
                s[index] = ' ';
                sum += atoi(s);
            }            
        }
        index++;
    }
    return sum;
}

int bracket()
{
    int sum = atoi(s);

    for(int i = 0; s[i]; i++)
    {
       if (s[i] >= '0' && s[i] <= '9')
       {
           s[i] = ' ';
       }
       else
       {
           if (s[i] == '+')
           {
               s[i] = ' ';
               sum += atoi(s);
           }
           else if (s[i] == '-')
           {
               s[i] = ' ';
               sum -= cal_minus(i);
           }
       }
    }
    return sum;
}

int main(void)
{
    scanf("%s", s);

    printf("%d\n",bracket());
}