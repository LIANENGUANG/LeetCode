//
// Created by egl1an on 2023/10/22.
//
#include "predefs.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;// 使用异或操作找出不同的位
        int count = 0;
        while(z) {
            count++;
            z &=(z -1); //去除最低位的 1
        }
        return count;
    }
};