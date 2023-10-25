//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // 找到目标最左边的位置
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                // 当出现等于目标值时，应该继续在左半部分找
                right = mid - 1;
            }
        }

        // 当退出上面的while循环时，如果未找到目标，则返回[-1, -1]
        // 任何时候都不要忘记考虑边界溢出的问题
        if(left >= nums.size() || nums[left] != target){
            return {-1, -1};
        }

        // 找到目标的最右边的值
        int start = left;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                // 当出现等于目标值时，应该继续在右半部分找
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return {start,right};
    }
};