#include<iostream>

using namespace std;

const int N = 1e6+10;
const int M = 1e5+10;

char p[N],s[M];

int main()
{
    int n,m;
    cin>>m>>s+1>>n>>p+1;
    int ne[m];
    //先写匹配再写生成，原串以1开头，模式串以0开头
    //生成next
    for(int i = 2,j=0;i<=m;++i)
    {
        while(j&&s[j+1]!=s[i])j = ne[j];
        if(s[j+1]==s[i])
        {
            ++j;
        }
        ne[i] = j;
    }

    //匹配
    for(int i = 1, j = 0;i<=n;i++)
    {
        while(j&&s[j+1]!=p[i])j = ne[j];
        if(s[j+1] == p[i]) ++j;
        if(j == m)cout<<i-m+1<<' ';
    }
    return 0;
    
}