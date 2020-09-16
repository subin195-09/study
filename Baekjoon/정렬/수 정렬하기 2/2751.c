#include <stdio.h>
int n;

void merge(int *num, int start, int mid, int end)
{
    int temp[n];
    int s = start;
    int m = mid + 1;
    int temp_index = start;

    while (s <= mid && m <= end)
    {
        if(num[s] < num[m])
            temp[temp_index++] = num[s++];
        else
            temp[temp_index++] = num[m++];
    }
    while (s <= mid) temp[temp_index++] = num[s++];
    while (m <= end) temp[temp_index++] = num[m++];

    for(int i = start; i <= end; i++)
        num[i] = temp[i];
}

void merge_sort(int *num, int start, int end)
{
    int mid = (start + end) / 2;
    if (start < end)
    {
        merge_sort(num, start, mid);
        merge_sort(num, mid + 1, end);

        // 병합
        merge(num, start, mid, end);
    }
}

void swap(int *num, int i, int j)
{
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

void build_heap(int *num, int n)
{
    for(int i = 1; i < n; i++)
    {
        int child = i;
        while(child > 0)
        {
            int root = (child - 1) / 2;
            if (num[root] < num[child])
                swap(num, root, child);
            child = root;
        }
    }
}

void heapify(int *num, int n)
{
    int parent = 0;
    int child = 1;
    while (child < n)
    {
        // 왼쪽 child
        child = parent * 2 + 1;

        // child들 중 큰값을 선택
        if (child + 1 < n && num[child] < num[child + 1])
            child++;
        
        if (child < n && num[parent] < num[child])
            swap(num, parent, child);
        
        parent = child;
    }
}

void heap_sort(int *num, int n)
{
    // root(num[0])에 제일 큰 수가 오게됨
    build_heap(num, n);

    for(int i = n - 1; i >= 0; i--)
    {
        swap(num, i, 0);
        heapify(num, i);
    }
}

int partition(int *num, int start, int end)
{
    int pivot = num[start];
    int s = start + 1;
    int e = end;
    while(s <= e)
    {
        while(s <= end && num[s] <= pivot)
            s++;
        while(e - 1 >= start && num[e] >= pivot)
            e--;
        if (s <= e)
            swap(num, s, e);
    }

    // 위치 e를 기준으로 작은건 왼쪽, 큰건 오른쪽으로 바뀜
    swap(num, start, e);

    return e;
}

int quick_sort(int *num, int start, int end)
{
    if (start <= end)
    {
        int pivot = partition(num, start, end);
        quick_sort(num, start, pivot - 1);
        quick_sort(num, pivot + 1, end);
    }
}

// 시간 복잡도 O(n * log(n))
int main(void)
{
    scanf("%d", &n);

    int num[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    // 합병정렬
    merge_sort(num, 0, n - 1);
    
    // 힙 정렬
    //heap_sort(num, n);

    // 퀵 정렬
    // 최악의 경우 시간 복잡도가 n * n
    //quick_sort(num, 0, n - 1);

    for(int i = 0; i < n ; i++)
        printf("%d\n", num[i]);
}