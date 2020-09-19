#include <stdio.h>

// 피사노 주기 : 파보나치 수를 k로 나눈 나머지는 주기를 갖는다
// 주기의 길이 : P, N번째 피보나치 수를 M으로 나눈 나머지는
// N % P번째 피보나치 수를 M으로 나머지와 같다
int main(void)
{
    long long n;
    scanf("%lld", &n);
    
    int mod = 1000000;
    // M = 10^k일때 (단, k > 2), P = 15 * 10^(k -1)
    int p = 15*(mod / 10);

    int fibo[p];
    fibo[0] = 0; fibo[1] = 1;
    for(int i = 2; i < p; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
    
    printf("%d\n", fibo[n % p]);
}