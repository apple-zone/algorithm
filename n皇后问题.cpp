/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-03-04 20:05:23
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-03-04 20:53:49
 * @FilePath: /algorithm/n皇后问题.cpp
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N = 10;
int n;

bool col[N],bg[2*N],nbg[2*N];

char g[N][N];


void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; ++i)
        {
            puts(g[i]);
        }
        return;
    }
    for(int i = 0; i < n ; ++i)
    {
        if(!col[i]&&!bg[u+i]&&!nbg[n+i-u])
        {
            g[u][i] = 'Q';
            col[i]=bg[u+i]=nbg[n+i-u]=true;
            dfs(u+1);
            col[i]=bg[u+i]=nbg[n+i-u]=false;
            g[u][i] = '.';
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int u = 0; u < n; ++u)
    for(int i = 0; i < n; ++i)
    {
        g[u][i]='.';
    }
    dfs(0);
    return 0;

}