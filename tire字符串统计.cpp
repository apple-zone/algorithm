#include<iostream>

using namespace std;

const int N = 10010;
int son[N][26],cnt[N],idx;//下标为0的点，既是根节点又是空节点
char str[N];

//如下两函数为tire树模板
//p表示层号，u表示子节点号
void insert(char str[])
{
    int p = 0;
    for(int i = 0;str[i];i++)
    {
        int u = str[i]-'a';
        if(!son[p][u]) son[p][u] = ++idx;//idx表示总节点号
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0;str[i];++i)
    {
        int u = str[i]-'a';
        if(!son[p][u])
        {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n = 0;
    cin>>n;
    for(int i = 0;i<n; ++i)
    {
        char c;
        cin>>c;
        cin>>str;

        if(c=='I')//插入
        {
            insert(str);
        }else 
        {
            int res = query(str);
            cout<<res<<endl;
        }

    }
    return 0;
}