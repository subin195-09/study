#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long gcd(int a, b)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    
    while (a != 0)
    {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

// w/gcd = w' , h/gcd = h'
// w' X h' 크기의 사각형이 gcd 만큼 생긴다
// w' X h' 사각형에서 직선이 지나가는 사각형의 수는 (w' + h' - 1)개 이다
// 따라서 총 직선이 지나가는 사각형의 갯수는 gcd * (w' + h' - 1) => w + h - gcd 이다
long long solution(int w, int h) {
    long long answer = 1;
    
    // (long long) 형 변환에 유의할 것
    answer = (long long)w * (long long)h - (w + h - (long long)gcd(w, h));
    
    return answer;
}