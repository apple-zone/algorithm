#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int l, r;
int ans = 0;

void dfs(LL x)
{
    if (x > r)
        return;
    if (x >= l && x >= 10)
        ans++;
    int d = x % 10;
    if (d)
        dfs(x * 10 + d - 1);
    if (d < 9)
        dfs(x * 10 + d + 1);
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d%d", &l, &r);
        ans = 0;
        for (int i = 1; i <= 9; ++i)
            dfs(i);
        printf("%d\n", ans);
    }

    return 0;
}