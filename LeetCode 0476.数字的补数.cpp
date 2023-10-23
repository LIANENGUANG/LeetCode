//
// Created by egl1an on 2023/10/23.
//
#include "predefs.h"

class Solution {
public:
    int findComplement(int num) {
        int temp = num;
      	// 防止mask溢出，因为mask比num多一位，因此如果num非常大，把mask定义成int一定会超出
        long long mask = 1;
        // 通过将mask左移并和num做或操作，确保mask成为一个与num位数相同并全为 1 的数
        while (temp) {
            mask <<= 1;
            temp >>= 1;
        }
        // 减 1 操作使得真正得到那个全 1 的mask
        return num ^ (mask - 1);
    }
};