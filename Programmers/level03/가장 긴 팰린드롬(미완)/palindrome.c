#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int find_palin(char *s, int index, int size)
{
    int temp_i = index;
    int j;
    int count = 0;
    
    for(j = size - 1; j > index; j--)
    {
        if(s[index] == s[j])
        {
            index++;
            count++;
        }
        else
        {
           index = temp_i;
            count = 0;
        }
    }
    if (j == index)
        count = count * 2 + 1;
    else if (j < index)
        count = count * 2;
    return count;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    int size = strlen(s);
    
    for (int i = 0; i < size; i++)
    {
        int temp = find_palin(s, i, size);
        if (answer < temp)
            answer = temp;
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("%d\n", answer);

    return answer;
}