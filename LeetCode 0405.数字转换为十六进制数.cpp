//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0"; // 按照题目处理特殊情况 0

        string hex = "0123456789abcdef"; //将数字映射到十六进制字符。
        string result = ""; // 初始化结果字符串
        // 32 位整数最多 8 个十六进制字符，直到 num 为 0。
        for (int i = 0; i < 8 && num; ++i) {
            //获取 num 的最后 4 位，并将相应的十六进制字符添加到结果中。
            result = hex[num & 0xf] + result;
            //将 num 右移 4 位以处理接下来的高 4 位。
            num >>= 4;
        }
        return result;
    }
};