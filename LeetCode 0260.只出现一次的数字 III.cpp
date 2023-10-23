//
// Created by egl1an on 2023/10/23.
//
# include "predefs.h"

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        //首先得到两个只出现一次的数字的异或结果
        int xor_result = 0;
        for (int num: nums) {
            xor_result ^= num;
        }

        // 找到xor_result 中的任意一个为 1 的位
        int diff_bit = 1;
        // 如果与完结果是 0 ，说明xor_result的diff_bit位
        while ((diff_bit & xor_result) == 0) {
            diff_bit <<= 1;
        }

        // 利用diff_bit将数组中的数字分为两组
        // 此时这两个数绝对不可能在同一组，因此他们在这个diff_bit位的值不相同
        // 而与完结果必定是他们，因为那些数成对出现，自己异或自己为 0
        int num1 = 0, num2 = 0;
        for (int num: nums) {
            if (num & diff_bit) {
                num1 ^= num;
            } else{
                num2 ^= num;
            }
        }
        return {num1,num2};
    }
};