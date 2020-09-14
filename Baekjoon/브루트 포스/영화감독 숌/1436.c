#include <stdio.h>

int get_number(int n)
{
    int num = 666;
    int count = 1;
    while(1)
    {
        // 찾은 수가 n번째라면 return
        if(count == n)
            return num;
        num++;
        int temp_num = num;
        // 숫자에 666이 포함되어있는지 확인
        while(temp_num > 0)
        {
            if(temp_num % 1000 == 666)
            {
                count++;
                break;
            }
            temp_num /= 10;
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", get_number(n));
}