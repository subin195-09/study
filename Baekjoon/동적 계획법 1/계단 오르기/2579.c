#include <stdio.h>

//입력받은 계단
int stair[301];

// 선택 한 계단의 최대 값을 입력
long sel[301];

long max(int a, int b) {return a > b ? a : b;}

// 1) n - 2 계단(최댓값)을 밟고 n 계단을 밟는 경우
// 2) n - 3 계단(최댓값), n - 1 계단 밟고 n 계단을 밟는 경우
// 2가지 경우의 수 중 max 값을 찾으면 된다
long find_max(int n)
{
    int step = 0;

    sel[1] = stair[1];
    sel[2] = stair[1] + stair[2];
    for(int i = 3; i <= n; i++)
        sel[i] = max(sel[i - 2], sel[i - 3] + stair[i - 1]) + stair[i];
    
    return sel[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &stair[i]);

    printf("%ld\n", find_max(n));
}