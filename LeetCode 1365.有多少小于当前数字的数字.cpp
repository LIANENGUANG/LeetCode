//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        // 创建一个数组来存储每个数字的出现次数
        vector<int> count(101, 0);
        // 创建一个数组来存储结果
        vector<int> result(nums.size(), 0);

        // 计算每个数字的出现次数
        for (int num: nums) {
            count[num]++;
        }

        // 计算小于当前数字的数字的总数
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }

        // 找到每个数字小于当前数字的数字的数量
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result[i] = count[nums[i] - 1];
            }
        }
        return result;
    }
};