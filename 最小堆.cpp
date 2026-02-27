#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N], heap_size;


void heap_swap(int a,int b)
{
    swap
}

void down(int x)
{
    //取最小值的索引交换,可以保证排序 稳定性
    int t = x;
    if(2*x<=heap_size&&h[2*x]<h[t])t = 2*x;
    if(2*x+1<=heap_size && h[2*x+1]<h[t]) t = 2*x+1;
    if(x!=t)
    {
        swap(h[x],h[t]);
        down(t);
    }
    return;
}

void up(int x)
{
    while(x/2 && h[x/2]>h[x])
    {
        swap(h[x],h[x/2]);
        x /= 2;
    }
    return ;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
    }
    heap_size = n;
    for (int i = n / 2; i; --i) // 自底向上维护
    {
        down(i);
    }
    while (m--)//按序输出最小的m个数
    {
        printf("%d ", h[1]);
        h[1] = h[heap_size];
        heap_size--;
        down(1); // 维护
    }
    return 0;
}