#include <iostream>

using namespace std;

const int N = 10010;

// head表示头节点的下标，e和ne分别表示value和下一节点下标
int head, e[N], ne[N];

// 临时指针
int idx;

void init()
{
    head = -1;
    idx = 0;
}
// 在链表头部插入节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
    return;
}
// 将值为X的节点插入下标k的节点的后面
void add(int des, int X)
{
    e[idx] = X;
    ne[idx] = ne[des];
    ne[des] = idx++;
}
// 将下标des点后的节点删除
void remove(int des)
{
        ne[des] = ne[ne[des]];
}
int main()
{
    int m = 0;
    cin >> m;
    char op;
    int x, des;
    init();
    for (int i = 0; i < m; ++i)
    {
        cin >> op;
        switch (op)
        {
        case 'H':
            cin >> x;
            add_to_head(x);
            break;
        case 'D':
            cin >> des;
            if(!des) head = ne[head];
            remove(des-1);
            break;
        default:
            cin >> des >> x;
            add(des-1, x);
            break;
        }
    }
    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    return 0;
}