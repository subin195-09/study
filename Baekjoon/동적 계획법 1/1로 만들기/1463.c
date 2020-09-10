#include <stdio.h>

int arr[1000001];

int min(int a, int b) {return a > b ? b : a;}

// 1) 2, 3의 제곱수라면 2, 3으로 나누는게 최선
// 2) 그저 배수일 경우 2, 3으로 나눈 후 -1 을 해준다
// 1, 2 과정을 반복
int make_one(int n)
{
   arr[1] = 0;
   for(int i = 2; i <= n; i++)
   {
       // -1 연산을 한 경우
       // i가 2, 3의 배수가 아니라면
       // i - 1은 무조건 2의 배수가 된다
       arr[i] = arr[i - 1] + 1;
       if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
       if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
   }

   return arr[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", make_one(n));
}