#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sum[i] : cookie[i]까지 쿠키 총 갯수
int *sum;

// cookie_len은 배열 cookie의 길이입니다.
int solution(int cookie[], size_t cookie_len) {
    int answer = 0;
    
    if (!(sum = (int *)malloc(sizeof(int) * cookie_len)))
        return (int)NULL;
    
    sum[0] = cookie[0];
    for (int i = 1; i < cookie_len; i++)
        sum[i] = sum[i - 1] + cookie[i];
    
    for(int i = 0; i < cookie_len - 1; i++)
    {
        // 첫째 아들의 쿠키수
        int sum_one = sum[i];
        for(int j = i + 1; j < cookie_len; j++)
        {
            // 둘째 아들의 쿠키 수
            int sum_two = sum[j] - sum_one;
            
            // 첫째 아들의 쿠키가 최댓값 보다 작을 때  or 첫째 아들의 쿠키가 둘째 아들의 쿠키보다 작을때
            // for문 밖으로 나가 첫째 아들의 쿠키를 증가 시켜 준다.
            if (answer > sum_one || sum_two > sum_one) break;
            
            // 둘째 아들의 쿠키수가 최댓값보다 작을 경우
            // 둘째 아들의 쿠키수를 증가 시켜 준다
            if (answer > sum_two) continue;
            
            // 첫째아들의 쿠키수 = 둘째 아들의 쿠키수 일 경우
            if (sum_two == sum_one && answer < sum_two)
            {
                answer = sum_two;
                break;
            }
            
            // 첫째 아들의 쿠키수 > 둘째 아들의 쿠키수 일 경우
            // 둘째 아들의 쿠키수 고정 & 첫째 아들의 쿠키수 감소
            for(int k = 0; k < i; k++)
            {
                if (sum_two == sum_one - sum[k] && answer < sum_two)
                {
                    answer = sum_two;
                    break;
                }
            }
        }
    }
    
    return answer;
}