//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        // 对数组进行排序
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // 三个最大正数的乘积
        // 亦或者是数组中只有三个数（则无论正负）
        int prod1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        // 他也有可能是最大的整数与两个最小的负数的乘积，注意是可能
        int prod2 = nums[0] * nums[1] * nums[n - 1];

        // 返回两者中的较大值
        //
        return max(prod1, prod2);
    }
};