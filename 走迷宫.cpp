/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-03-04 21:20:00
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-03-04 21:35:24
 * @FilePath: /algorithm/走迷宫.cpp
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */     
#include<iostream>
#include<algorithm>
#include<cstring>
// #include<queue>

using namespace std;

typedef pair<int ,int> PII;

const int N = 10010;

int n,m;
int g[N][N];
int d[N][N];
PII q[N * N]; 
// int prev[N][N];//用来记录路径

int bfs()
{
    int hh = 0,tt = 0;
    q[0] = {0 , 0};

    memset(d,-1,sizeof d);//所有点都没走过
    d[0][0] = 0;
    while(hh <= tt)
    {
        auto t = q[hh++];
        int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
        for(int i = 0; i < 4; ++i)
        {
            int x = dx[i] + t.first, y = dy[i] + t.second;
            if(x >= 0&& x <n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1; 
                q[++tt]  = {x,y};
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >>g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}  