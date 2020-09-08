#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int size = strlen(s);
    int left;
    int right;
    
    for(int start = 0; start < size; start++)
    {
        // last가 substring의 길이가 된다
        for(int last = size; last > answer; last--)
        {
            left = start;
            right= left + last - 1;
            
            while(s[left] == s[right] && left < right)
            {
                left++;
                right--;
            }
            if(left >= right){
                // last가 현재 찾은 팰린드롬 보다 크다면 answer을 바꿔준다
                if(answer < last){
                    answer = last;
                    break;
                }
            }
        }
    }

    return answer;
}