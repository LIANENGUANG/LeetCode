//
// Created by egl1an on 2023/10/22.
//
#include "predefs.h"
class Solution {
public:
    int getSum(int a, int b) {
        while(b!= 0){
            // 计算进位
            int carry = unsigned (a &b) << 1;
            // 不考虑进位的结果
            a = a ^ b;
            // 将进位的结果赋给b
            b= carry;
        }
        return a;
    }
};