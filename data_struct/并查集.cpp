#include<iostream>

using namespace std;

const int N = 1e5+10;
int n,m;
int p[N];

int find(int x)//返回x的祖宗节点
{
    if(p[x]!=x)x = find(p[x]);
    return p[x];
}

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=N;++i)
    {
        p[i] = 1;
    }
    while(m--)
    {
        char op[2];//防止直接用char会意外读入一些空格回车等字符
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M')
        {
            p[find(a)] = find(b); 
        }else{
            if(p[find(a)]==p[find(b)]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}