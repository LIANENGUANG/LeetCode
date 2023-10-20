//
// Created by egl1an on 2023/10/20.
//
#include "predefs.h"

class Solution {
public:
    string intToRoman(int num) {
        // 罗马数字和相应的整数值
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        for (int i = 0; i < values.size() && num > 0; i++) {
            // 循环减去最大的那一个
            while (num >= values[i]) {
                num -= values[i];
                // 将对应的罗马字符加到字符串中
                result += symbols[i];
            }
        }
        return result;

    }
};