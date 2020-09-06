#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// qsort시 compare 규칙
// 두 문자를 붙였을때 좀 더 큰수가 되도록 정렬한다
int static compare(const void *first, const void *second)
{
    char a[9];
    char b[9];
    sprintf(a, "%d%d", *(int *)first, *(int *)second);
    sprintf(b, "%d%d", *(int *)second, *(int *)first);
    
    // 내림차순으로 정렬
    return strcmp(b, a);
}

// numbers_len은 배열 numbers의 길이입니다.
char *solution(int numbers[], size_t numbers_len)
{
    int answerSize = 0;
    for (int i = 0; i < numbers_len; i++)
    {
        // "%d"에서 출력된 결과물이 buf에 저장됨
        char buf[5];
        sprintf(buf, "%d", numbers[i]);
        answerSize += strlen(buf);
    }
    
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char *answer = (char *)malloc(sizeof(char) * (answerSize + 1));
    
    for (int i = 0; i <= answerSize; i++)
        answer[i] = '\0';
    
    // qsort(정렬하고자 하는 배열, 배열 길이, 배열 원소 하나의 크기, 비교할 함수 포인터)
    // 함수 포인터는 1, 0, -1만을 출력해야 한다
    // 참 : 1, 거짓 : -1, 같을 때  : 0
    qsort(numbers, numbers_len, sizeof(int), compare);
    
    // 모든 원소가 0일때
    if(numbers[0] == 0)
        return "0";
    
    for (int i = 0; i < numbers_len; i++)
    {
        char buf[5];
        sprintf(buf, "%d", numbers[i]);
        strcat(answer, buf);
    }
    
    return answer;
}