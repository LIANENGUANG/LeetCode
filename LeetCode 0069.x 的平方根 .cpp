//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        // 一个非负正数的平方根肯定在1 到 x之间
        int left = 1, right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 由于我们需要整数部分的平分根，所以这里需要除法
            // 刚好找到
            if (mid == x / mid) {
                return mid;
            }
                // 如果mid < x /mid 说明 mid * mid < x
                // 说明当前的mid值不够
            else if (mid < x / mid) {
                // 提升值范围
                left = mid + 1;
            } else {
                // 减少值范围
                right = mid - 1;
            }
        }
        // 应该取较小的整数才是整数部分的平方根
        return right;
    }
};