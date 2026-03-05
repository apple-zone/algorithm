/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-03-04 19:27:45
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-03-04 20:37:01
 * @FilePath: /algorithm/全排列数字输出.cpp
 * @Description:
 *
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved.
 */
// 按照字典序给出从1~n的数字的所有排列方案
#include <iostream>

using namespace std;

const int N = 10;
int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            // path[u] = 0;
            st[i] = false;//恢复现场 
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}