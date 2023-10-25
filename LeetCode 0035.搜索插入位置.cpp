//
// Created by egl1an on 2023/10/13.
//
#include "predefs.h"

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        // 初始化左指针和右指针
        int left = 0;
        int right = nums.size() - 1;

        // 当左指针不大于右指针时，继续查找
        while (left <= right) {
            // 计算中间位置
            int mid = left + (right - left) / 2;

            // 如果中间位置的值等于目标值，直接返回此位置
            if (nums[mid] == target) {
                return mid;
            }
            // 如果中间位置的值小于目标值，说明目标值应该在中间位置的右边
            else if (nums[mid] < target) {
                // 将左指针移动到中间位置的右边
                left = mid + 1;
            }
            // 如果中间位置的值大于目标值，说明目标值应该在中间位置的左边
            else {
                // 将右指针移动到中间位置的左边
                right = mid - 1;
            }
        }

        // 当循环结束，如果没有找到目标值，左指针将指向目标值应该插入的位置
        return left;
    }
};


//二分法