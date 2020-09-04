#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = false;
    long long sum = 0;
    int temp = x;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    if (temp % sum == 0)
        answer = true;
    return answer;
}