
//
// Created by egl1an on 2023/10/22.
//
#include "predefs.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;  // 用于计数二进制中'1'的个数

        while (n) {  // 当n不为0时
            count++;  // 增加计数器
            n &= (n - 1); // 使用位操作去除最低位的'1'
        }

        return count;  // 返回'1'的数量
    }
};