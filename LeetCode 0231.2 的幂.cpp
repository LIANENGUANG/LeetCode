//
// Created by egl1an on 2023/10/22.
//
# include "predefs.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 当 n 为正数，并且 n与 n -1 的与操作为 0 时，n是 2 的幂
        return n > 0 && (n & (n - 1)) == 0;

    }
};