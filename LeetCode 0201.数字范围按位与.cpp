//
// Created by egl1an on 2023/10/23.
//

#include "predefs.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // 找到公共前缀
        // 同时右移直到二者相等，说明找到了公共前缀
        while (left < right){
            left >>=1;
            right >>=1;
            // 记录移动的次数，以方便补 0 找到这个公共前缀所代表的具体的数
            ++shift;
        }
        // 将公共前缀左移回原来的位置
        return left << shift;
    }
};

