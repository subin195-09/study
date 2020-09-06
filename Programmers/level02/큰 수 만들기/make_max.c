#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *answer;

// number[start] ~ number[end] 중 최댓값을 구한다
int find_max(char *number, int start, int end)
{
    char max = '0';
    int index_max = start;
    for(int i = start; i <= end; i++)
    {
        if (number[i] > max)
        {
            max = number[i];
            index_max = i;
        }
    }
    return index_max;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int start = 0;
    int len = strlen(number);
    int answer_size = len - k;
    answer = (char*)malloc(sizeof(char) * (answer_size + 1));
    answer[answer_size] = '\0';
    
    for(int i = 0; i < answer_size; i++)
    {
        start = find_max(number, start, k + i);
        answer[i] = number[start++];
    }
    
    return answer;
}