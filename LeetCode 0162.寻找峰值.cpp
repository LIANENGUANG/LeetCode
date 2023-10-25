//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 中间元素小于其右侧元素，则他必定不是峰顶则跳过
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
                // 但是如果中间元素大于等于右侧元素，则他有可能是峰顶，或者峰顶在mid的左侧区间
            } else {
                right = mid;
            }
        }
        return left;
    }
};