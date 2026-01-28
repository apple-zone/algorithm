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