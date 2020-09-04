#include <stdio.h>
#include <math.h>

// n : 원판의 갯수
// from에 꽂혀 있는 n개의 원반을 by를 거쳐 to 로 이동
// n - 1개를 2번째로 이동후
// n을 3으로 이동한다
// 그후 (n - 1)개를 다시 3으로 이동

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
        printf("%d %d\n", from, to);
    else
    {
        // n - 1개를 from에서 by로 이동
        hanoi(n - 1, from, to, by);

        // 1개를 from에서 to로 이동
        printf("%d %d\n", from, to);

        // n - 1개를 다시 by에서 to로 이동
        hanoi(n - 1, by, from, to);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    // 하노이 탑 횟수 : 2^n - 1
    printf("%d\n", (int)pow(2, n) - 1);

    hanoi(n, 1, 2, 3);
}