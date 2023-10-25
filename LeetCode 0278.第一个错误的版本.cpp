//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            // 计算中间版本号
            int mid = left + (right - left) / 2;

            //  如果中间版本号为错误版本号，继续往时间轴之前找，也就是左半部分
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 返回最左边的也就是第一个错误的版本号
        return left;
    }
};