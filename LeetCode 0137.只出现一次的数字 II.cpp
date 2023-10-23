//
// Created by egl1an on 2023/10/23.
//
#include "predefs.h"

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        // 遍历 每个数（是32 位表示的）的每一位
        for (int i = 0; i < 32; i++) {
            // 准备计算当前位上 1 出现的次数，注意这里所说的位是针对所有的数的第i位
            int sum = 0;
            // 对于每个数计算其第i 位上 1 出现的次数
            for (int num: nums) {
                if ((num >> i) && 1) {
                    sum++;
                }
            }
            // 将这一位的值加到结果当中，当i等于 0 时，左移 0 位相等于没动
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};