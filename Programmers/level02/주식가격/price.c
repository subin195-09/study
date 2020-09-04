#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    for (int i = 0; i < prices_len; i++)
        answer[i] = 0;
    for (int i = 0; i < prices_len - 1; i++)
    {
        for (int j = i + 1; j < prices_len; j++)
        {
            answer[i]++;
            if (prices[i] > prices[j])
                break;
        }
    }
    return answer;
}