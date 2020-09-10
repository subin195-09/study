#include <stdio.h>

int count_zero[41];
int count_one[41];

int count_fibo(int n)
{
    count_zero[0] = 1;
    count_one[0] = 0;

    count_zero[1] = 0;
    count_one[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        count_zero[i] = count_zero[i - 1] + count_zero[i - 2];
        count_one[i] = count_one[i - 1] + count_one[i - 2];
    }  
}

int main(void)
{
    // 테스트 케이스의 갯수
    int n;
    scanf("%d", &n);

    count_fibo(40);

    // 재귀함수로 풀었을때 0, 1의 호출수를 출력
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        printf("%d %d\n",count_zero[num], count_one[num]);   
    }
}
