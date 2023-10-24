//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    int secondHighest(string s) {
        // 使用 Bool数组记录每个数字是否出现过
        bool appeared[10] = {false};

        for (char c: s) {
            if (isdigit(c)) {
                // 标记这个数字已经出现过，减'0'字符是一个常用的技巧
                appeared[c - '0'] = true;
            }
        }

        bool foundFirst = false;
        for (int i = 9; i >= 0; i--) {
            // 先确定一个当前最大的
            if (appeared[i]) {
                // 如果已经有当前最大的了，此时又找到一个则是第二大的
                if (foundFirst) {
                    return i; // 返回第二大的数字
                }
                foundFirst = true;
            }
        }
        return -1; // 没有找过第二大的数字
    }
};