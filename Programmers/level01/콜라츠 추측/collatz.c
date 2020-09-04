#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    long long temp = num;
    while (temp != 1)
    {
        if (temp % 2 == 0)
            temp /= 2;
        else
            temp = temp * 3 + 1;
        answer++;
    }
    
    return (answer >= 500 ? -1 : answer);
}