#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    long long fibo[n];
    int i;
    
    fibo[0] = 0;
    fibo[1] = 1;
    for (i = 2; i < n + 1; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
    answer = fibo[n];
    return (answer < 2) ? 1 : answer;
}