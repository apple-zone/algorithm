#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
char p[N], s[M]; // 匹配串和模式串
int ne[N];       // next数组,next的名称看你能在引入某些头文件时会报错（重复定义）

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    // 求next,实际上时自匹配
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && p[i] != p[j + 1])
        {
            j = ne[j];
        }
        if (p[i] == p[j + 1])
            ++j;
        ne[i] = j;
    }
    // 匹配过程
    for (int i = 1, j = 0; i <= m; ++i) // 此处决定了是i和j+1
    {
        while (j && s[i] != p[j + 1])
        // 当前无法继续匹配,除非到退无可退，否则向前迭代
        {
            j = ne[j];
        }
        if (s[i] == p[j + 1])
            ++j;
        if (j == n)
        {
            // 匹配成功,输出初次匹配成功的位置
            printf("%d", i - n);
            j = ne[j];
        }
    }
    return 0;
}