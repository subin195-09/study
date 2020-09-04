#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    answer[3] = '\0';
    char *days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    for (int i = 0; i < a - 1; i++)
        b += month[i];
    answer = days[(b + 4) % 7];
    
    return answer;
}