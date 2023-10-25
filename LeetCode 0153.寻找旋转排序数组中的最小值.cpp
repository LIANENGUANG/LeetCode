//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // 确定中间位置
            int mid = left + (right - left) / 2;

            // 如果中间的数大于右边的数，说明最小的数在右半部分
            // 并且最小值肯定不是当前这个mid索引所对应的数
            // 因此直接跳过mid
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
                // 此时nums[mid] <= nums[right]
                // 因此最小的数在左半部分或就是中间的那个数
                // 所以不能是right = mid -1，这会忽略当前这个mid就是那个最小值的可能
            else {
                right = mid;
            }

        }
        return nums[left]; // 返回数组中的最小值
    }
};