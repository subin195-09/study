#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DP 알고리즘 활용
// (num)' : num칸 일 때 갈 수 있는 경우의 수
// n칸일때 : (n - 1)' + (n - 2)' + ... + 1'
// 알고리즘이 피보나치 수열의 형태와 같다
// tmp[i] : (i + 1)칸일 때 갈 수 있는 가짓수
int jump(int n)
{
    int tmp[2000];
    
    tmp[0] = 1;
    tmp[1] = 2;
    for(int i = 2; i < n; i++)
        tmp[i] = (tmp[i - 2] + tmp[i  - 1]) % 1234567;
    return tmp[n - 1];
}

long long solution(int n) {
    long long answer = 0;
    
    answer = jump(n);

    return answer;
}