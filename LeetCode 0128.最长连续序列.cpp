//
// Created by egl1an on 2023/10/30.
//
#include "predefs.h"

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num: nums) {
            // 判断当前数是否为连续序列的开始
            // 在num_set当中没有找到num - 1的话,只有这种情况下才有可能序列的开始
            // 如果没找到.count()返回 0,!0 为真,进入循环,此时长度至少是 1,所以currentNum初始化为 1.
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                // 从当前数字查找连续序列,依次加 1，查找连续的数字并统计长度
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                // 更新最大连续序列的长度
                longest = max(longest, currentStreak);
            }

        }
        return longest;
    }
};