#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a와 b의 최소공배수 = a * b / a와 b의 최대공약수
// 1. i와 i + 1의 최소공배수를 구한다
// 2. 1과 i + 2의 최소공배수를 구한다

// 최대공약수
int cal_gcd(int a, int b)
{
    int temp;
    while (a != 0)
    {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

// 최소공배수
int cal_lcm(int a, int b)
{
    int gcd = cal_gcd(a, b);
    int lcm = (a * b) / gcd;
    return lcm;
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer;
    
    if (arr_len == 1)
        answer = arr[0];
    else
        answer = cal_lcm(arr[0], arr[1]);
    
    for (int i = 2; i < arr_len; i++)
        answer = cal_lcm(answer, arr[i]);
    return answer;
}