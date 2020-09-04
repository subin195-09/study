#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 효율성 테스트를 위해 quick sork 사용
void sort(int arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  // 배열의 중간값을 pivot으로 지정
  int pivot = arr[(left + right) / 2]; 

  // pivot을 기준으로 작은건 왼쪽 큰 건 오른쪽으로 정렬
  while (L <= R) {
    while (arr[L] < pivot) 
      L++;
    while (arr[R] > pivot) 
      R--;
    if (L <= R)
    {
        if (L != R)
        {
            temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
        }
        L++;
        R--;
    }
  }
  if (left < R)
      sort(arr, left, R);
  if (L < right)
      sort(arr, L, right);
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    
    sort(A, 0, A_len - 1);
    sort(B, 0, B_len - 1);
    
    // 남아있는 A의 최솟값 * 남아있는 B의 최댓값을 곱해 나간다
    for (int i = 0; i < A_len; i++)
        answer += A[i] * B[B_len - i - 1];
    
    return answer;
}