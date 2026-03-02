/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-03-02 20:53:41
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-03-02 21:17:06
 * @FilePath: /algorithm/模拟散列表（拉链法）.cpp
 * @Description:
 *
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof(h));

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I')
        {
            insert(x);
        }
        else
        {
            if (find(x))
                puts("yes");
            else
                puts("no");
        }
    }
}
