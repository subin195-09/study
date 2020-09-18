#include <stdio.h>

// AB mod C = (A mod C * B mod C) mod C
// b를 짝수로 만들어 
// a ^ (b/2) % c를 구해 곱한 다음 mod c를 해준다
long long mul(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    else if(b == 1)
        return (a % c);
    // b가 홀수일 경우
    if (b % 2 == 1)
        return (mul(a, b - 1, c) * a % c);
    long long half = mul(a, b / 2, c);
    half %= c;
    return (half * half) % c;
}

// a ^ b의 시간복잡도를 줄여보자
int main(void)
{
    int a;
    int b;
    int c;
    scanf("%d %d %d", &a, &b, &c);

    // a^b mod c
    printf("%lld\n", mul(a, b, c));
}