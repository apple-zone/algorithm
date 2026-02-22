/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-01-25 21:17:01
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-01-28 12:32:49
 * @FilePath: /algorithm/data_struct/单调队列.cpp
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include<iostream>

using  namespace std;

const int N = 1e6+10;

void minSlidingWindow(int nums[],int len,int size,int res[])
{
    int hh = 0,tt = 0;
    int n=0;//维护结果数组
    //结果和双端队列，队列保存的是数字在nums中的下标
    int dq[N];
    for(int i = 0;i<len;++i)
    {
        //维护窗口大小
        if(hh!=tt&&dq[hh]<=i-size) hh++;
        //维护单调队列
        while(hh!=tt&&nums[dq[tt-1]]>=nums[i])tt--;
        //添加当前节点
        dq[tt++] = i;
        //窗口够大时填入结果
        if(i-size+1>=0) res[n++] = nums[dq[hh]];
    }
    return;
    
}

int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i = 0;i<n;++i)
    {
        cin>>nums[i];
    } 
    int size;
    cin>>size;
    int res[N];
    minSlidingWindow(nums,n,size,res);
    for(int i = 0;i<n-size+1;++i) cout<<res[i]<<" ";
    return 0;
}