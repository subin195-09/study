#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    long long temp = n;
    long long count = 0;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(sizeof(int) * count);
    int i = 0;
    while (n > 0)
    {
        answer[i++] = n % 10;
        n /= 10;
    }
    
    return answer;
}