#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DP : 카탈린 수
// Cn = C0 * C(n-1) + C1 * C(n-2) + ... + C(n-1)*C0
// C0 = 1
int solution(int n) {
    int answer[n + 1];
    
    answer[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        answer[i] = 0;
        for(int j = 0; j <= (i - 1); j++)
            answer[i] += answer[i - (j + 1)] * answer[j];
    }
    
    return answer[n];
}