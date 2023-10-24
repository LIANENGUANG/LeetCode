//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for( int i = 0; i < 32 ;++i){
            // 腾出空间，放n的从后往前的位
            result <<= 1;
            if(n & 1) result++; // 说明当前位是 1
            n >>= 1; // n右移，处理下一个倒数位（从右往左）
        }
        return result;
    }
};