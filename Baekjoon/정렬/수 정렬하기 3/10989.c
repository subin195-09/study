#include <stdio.h>

// 카운팅 정렬
// 데이터 수가 클수록 메모리 효율성이 떨어짐
// 시간 복잡도 = O(n)
int main(void)
{
    int n;
    scanf("%d", &n);

    int count[10000] = {0};
    int max = 1;
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        count[temp - 1]++;
        if (max < temp)
            max = temp;
    }

    for(int i = 0; i < max; i++)
    {
        if (count[i] > 0)
        {
            for(int j = 0; j < count[i]; j++)
                printf("%d\n", i + 1);
        }
            
    }
}