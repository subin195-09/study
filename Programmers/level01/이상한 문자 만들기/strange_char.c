#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = strdup(s);
    int sub = 'a' - 'A';
    int i = 0;
    int check = 0;
    while (answer[i])
    {
        if (answer[i] == ' ')
            check = -1;
        if (check % 2 == 0)
        {
            if (answer[i] >= 'a' && answer[i] <= 'z')
                answer[i] -= sub;
        }
        else
        {
            if (answer[i] >= 'A' && answer[i] <= 'Z')
                answer[i] += sub;
        }
        check++;
        i++;
    }
    return answer;
}