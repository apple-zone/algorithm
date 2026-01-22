# 归并排序

```c++

#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N], tmp[N];

void merge_sort(int *q, int l, int r)
{
    if (l >= r)
        return;
    if (l + 1 == r)
    {
        if (q[l] > q[r])
        {
            swap(q[l], q[r]);
            return;
        }
    }
    merge_sort(q, l, (l + r) / 2);
    merge_sort(q, (l + r) / 2 + 1, r); 
    int k = 0, i = l, j = (l+r)/2+1;
    while (i <= (l + r) / 2 && j <= r)
    {
        if (q[i] < q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            tmp[k++] = q[j++];
        }
    }
    while (i <= (l + r) / 2)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) 
        q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }
    return 0;
}
```

当使用模板解决浮点数类型二分查找问题时，精度限制比保留小数位数高两位即可。
