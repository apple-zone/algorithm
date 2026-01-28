#include <iostream>

using namespace std;

const int N = 10010;

int head, e[N], l[N], r[N];

int idx;

void init()
{
    idx = 0;
    head = -1;
}

//添加一个节点到链头
void add_to_head(int x)
{
    e[idx] = x;
    l[idx] = -1, r[idx] = head;
    if (head != -1)
        l[head] = idx;
    head = idx++;
}

//删除一个节点
void remove(int des)
{
    if (des == head)
    {
        head = r[head];
        if (head != -1)
        {
            l[head] = -1; // 新头节点的左指针置为-1
        }
        return;
    }
    if (l[des] != -1)
        r[l[des]] = r[des];
    if (r[des] != -1)
        l[r[des]] = l[des];
}

//在索引des后添加一个节点
void add(int des, int x)
{
    if (des == head)
    {
        add_to_head(x);
        return;
    }
    e[idx] = x;
    l[idx] = des, r[idx] = r[des];
    l[r[des]] = idx, r[des] = idx;
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
            remove(des - 1);
            break;
        default:
            cin >> des >> x;
            add(des - 1, x);
            break;
        }
    }
    for (int i = head; i != -1; i = r[i])
    {
        cout << e[i] << ' ';
    }
    return 0;
}