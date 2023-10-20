// 单调队列
//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // 下摆哦（时间）递增，值递减的队
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 删除出界的选项
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            // 插入新选项i，维护单调性（值递减）
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            // 取对头更新答案
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }

private:
    deque<int> q; // 存储下标,双端队列
};