#include <stdio.h>

long long p = 1000000007;
long long fac[4000001];

// a^b mod p
long long mul(long long a, long long b)
{
    if (b == 0) return 1;
    else if (b == 1) return a;
    
    if (b % 2 == 0)
    {
        long long temp = mul(a, b / 2) % p;
        return (temp * temp) % p;
    }
    long long temp = mul(a, b - 1) % p;
    return (a * temp) % p;
}

// 페르마의 소정리 : a가 정수, p가 소수일때
// a^p % p = a % p ==> a^(p-1) = 1 % p ==> a^(p-2) % p = a^(p-1) % p
// => a의 역수(a^(-1))를 p로 나눈 나머지는 a^(-2) % p 와 같다
// 1000000007는 소수이므로 페르마의 소정리 이용
int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (k == 0 | k == n)
    {
        printf("1\n");
        return (0);
    }
    
    fac[1] = 1;
    for(int i = 2; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    // A = n!, B = {(n - k)! * k!}
    // A * B(p - 1) % p = A * B(p -2) % p
    // ==> (A % p)(B^(p - 2) % p) % p
    long long result;
        result = fac[n] * mul(fac[n - k] * fac[k] % p, p - 2);

    printf("%lld\n", result % p);   
}