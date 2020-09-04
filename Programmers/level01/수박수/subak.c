#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(200000);
    char *su = "수";
    char *bak = "박";
    
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            strcat(answer, su);
        else
            strcat(answer, bak);
    }
    return answer;
}