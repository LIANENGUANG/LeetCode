//
// Created by egl1an on 2023/10/13.
//
#include "predefs.h"

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        // 从最右边的数字（个位数）开始
        for (int i = n - 1; i >= 0; i--) {
            // 如果该位数字是9，则将其设置为0并继续检查下一个数字
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                // 如果该位数字小于9，将其加一并返回结果
                digits[i]++;
                return digits;
            }
        }
        // 如果我们到了这里，说明所有的数字都是9，我们需要在开始位置添加一个1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
