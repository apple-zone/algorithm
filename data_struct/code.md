```C++
/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-01-25 21:17:01
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-01-28 11:22:36
 * @FilePath: /algorithm/data struct/单调队列.cpp
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> minSlidingWindow(vector<int>& nums, int k)
{
    vector<int> res;
    deque<int> dq;  // 存储下标，单调递增队列
    //头部存储窗口尾部，尾部存储窗口头部
  
    for (int i = 0; i < nums.size(); i++) {
        // 窗口移动，移除不在窗口内的元素
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
  
        // 维护单调递增性
        while (!dq.empty() && nums[dq.back()] >= nums[i]) {
            dq.pop_back();
        }
  
        dq.push_back(i);
  
        // 当窗口形成时记录结果,窗口未填满时不输出
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
  
    return res;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
  
    cout << "滑动窗口最小值: ";
    vector<int> res = minSlidingWindow(nums, k);
    for (int num : res) {
        cout << num << " ";
    }
    // 输出: -1 -3 -3 -3 3 3
    return 0;
}


```

```C++
/*
 * @Author: apple-zone 2188563245@qq.com
 * @Date: 2026-01-27 21:39:50
 * @LastEditors: apple-zone 2188563245@qq.com
 * @LastEditTime: 2026-01-28 17:07:49
 * @FilePath: /algorithm/data_struct/KMP.cpp
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
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
//测试案例
/*
3
aba
8
abababab
*/
```
