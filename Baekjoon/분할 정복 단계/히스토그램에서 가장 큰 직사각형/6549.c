#include <stdio.h>

long long max(long long a, long long b) {return a > b ? a : b;}
long long min(long long a, long long b) {return a > b ? b : a;}

long long find_square(long long *s, int left, int right)
{
    if (left == right)
        return s[left];
    
    // 중간을 기준으로 잡는다
    int pivot = (left + right) / 2;
    long long result;
    result = max(find_square(s, left, pivot), find_square(s, pivot + 1, right));
    int ll = pivot, rr = pivot + 1;
    // pivot을 기준으로 낮은 기둥이 높이가 된다
    long long height = min(s[ll], s[rr]);
    int width = 2;
    // 최소 넓이
    result = max(result, height * width);

    while (left < ll || rr < right)
    {
        // 왼쪽에 더이상 사각형이 없거나
        // 오른쪽의 사각형이 더 큰 경우
        if (rr < right && (ll == left || s[ll - 1] <= s[rr + 1]))
        {
            rr++;
            height = min(height, s[rr]);
            width++;
        }
        // 오른쪽에 더이상 사각형이 없거나
        // 왼쪽의 사각형이 더 큰 경우
        else
        {
            ll--;
            height = min(height, s[ll]);
            width++;
        }
        result = max(result, height * width);
    }
    return result;
}

int main(void)
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        if(n == 0)
            return (0);
        else
        {
            long long s[n];
            for(int i = 0; i < n; i++)
                scanf("%lld", &s[i]);
            printf("%lld\n", find_square(s ,0 , n - 1));
        }
    }
}