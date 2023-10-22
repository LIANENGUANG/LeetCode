//
// Created by egl1an on 2023/10/22.
//
#include "predefs.h"

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int totalDistance = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num: nums) {
                bitCount += (num >> i) & 1; // 检查第i位是否为 1，如果是 1 返回 1 否则返回 0。因此可以用于统计
            }
            totalDistance += bitCount * (n - bitCount);  // 1的数量乘以0的数量
        }
        return totalDistance;
    }
};