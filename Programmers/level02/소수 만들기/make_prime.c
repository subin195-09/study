#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 뽑힌 3개의 수를 저장
int arr[3];
// 뽑힌 숫자를 check
int *check;
// 소수의 갯수 check
int answer;
// nums의 갯수
int n;

// 소수판별 함수
int is_prime(int num)
{
    for(int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// 백트랙킹
// nums배열 중 3개를 중복없이 뽑아
// 3개의 합이 소수이면 answer를 증가시켜준다
void dfs(int nums[], int index, int count)
{
    if (count == 3)
    {
        int sum = 0;
        for(int i = 0; i < 3; i++)
            sum += arr[i];
        if (is_prime(sum))
            answer++;
        return ;
    }
    
    for(int i = index; i < n; i++)
    {
        if (check[i])
        {
            arr[count] = nums[i];
            check[i] = 0;
            dfs(nums, i + 1, count + 1);
            check[i] = 1;
        }
    }
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    check = (int *)malloc(sizeof(int) * nums_len);
    n = nums_len;
    
    for (int i = 0; i < nums_len; i++)
        check[i] = 1;
    
    dfs(nums, 0, 0);
    return answer;
}