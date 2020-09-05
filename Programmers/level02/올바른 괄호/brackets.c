#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    int check = 0;
    int len = strlen(s);
    int i = 0;
    
    // ( , ) 가 짝이 맞는지 확인
    if (len % 2 != 0)
        return false;
    
    // ( 가 나오지 전에 ) 가 나오는지 확인
    while (s[i])
    {
        if (s[i] == '(')
            check++;
        else
            check--;
        if (check < 0)
            return false;
        i++;
    }
    
    // 남는 ( 가 있는지 확인
    if (check)
        return false;
    
    return answer;
}