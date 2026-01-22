## 双指针算法
- 核心思想：在特殊场景下将O(n^2)变为O(n)
```C++
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[1000];
    cin >> str;
    // gets(str);
    int n = strlen(str);
    for (int i = 0; str[i]; ++i)
    {
        int j = i;
        while (j < n && str[j] != ' ')
            ++j;

        // 具体逻辑
        for (int k = i; k < j; ++k)
        {
            cout << str[k];
        }
        cout << endl;
        i = j;
    }

    return 0;
}
```
### 双指针例题
```C++
#include <iostream>

using namespace std;

const int N = 1e6 + 1;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        s[a[i]]++;
        while(s[a[i]]>1) 
        {
            s[a[j]]--;
            ++j;
        }
        res = max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}
```
## 位运算
n的二进制表示中第k位是几
1. 先把第k位一道最后一位（个位） 
2. 判断奇偶，奇为1，偶为0 
## 离散化
