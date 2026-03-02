#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010,null=0x3f3f3f3f;
int h[N];

//找到则返回位置 否则返回填入位置
int find(int x)
{
    int addr  = (x%N+N)%N;
    while(h[addr]!=null &&h[addr]!=x)
    {
        ++addr;
        if(addr == N) addr = 0;
    }
    return addr;
}
int  main()
{
    int n;
    memset(h,0x3f,sizeof(h));//memset按照字节赋值
    char op[2];
    int x;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s%d",op,&x);
        int addr = find(x);
        if(*op=='I')  
        {
            h[addr] = x;
        }
        else{
            if(h[addr]==x)puts("yes");
            else puts("no");
        }
    }
    return 0;
}