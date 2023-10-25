//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        // 获取数组的长度
        int n = nums.size();
        // 初始化两个指针
        int i = 0, j = 1;

        while (i < n && j < n) {
            // 找到第一个位于偶数位置但是值为奇数的元素
            while (i < n && nums[i] % 2 == 0) {
                i += 2;
            }
            // 找到第一个位于奇数位置但是值为偶数的元素
            while (j < n && nums[j] % 2 == 1) {
                j += 2;
            }
            //如果两个指针都未到达数组的尾部，则交换着两个元素的位置
            if (i < n && j < n) {
                swap(nums[i], nums[j]);
            }
        }
        // 返回排序后的数组
        return nums;
    }
};