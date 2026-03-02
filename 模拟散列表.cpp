#include<iostream>

using namespace std;

const int N = 100010;

int h[N],e[N];

void insert(int x)
{
    int k = (x%N + N)% N;

}

int main()
{
    int n;
    scanf("%d",&n);

    memset(h,-1,sizeof(h));

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        if(*op =='I')
        {
            int y;
            scanf("%d",&y);
            insert(x,y);
        }
    }
}