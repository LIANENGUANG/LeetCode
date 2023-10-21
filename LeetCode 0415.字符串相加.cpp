//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        // i 和 j 作为num1和num2的两个指针，初始位置在各自的最后一个字符
        int i = num1.size() - 1, j = num2.size() - 1;
        // carry用来保存进位，初始化为0
        int carry = 0;
        // 用来保存结果的字符串
        string result = "";

        // 循环直到i和j都小于0且无进位
        while (i >= 0 || j >= 0 || carry) {
            // 从进位开始求和
            int sum = carry;
            // 如果i还没走到num1的开始，加上num1对应位置的数字
            if (i >= 0) sum += num1[i--] - '0'; // 由于字符到数字的转换，需要减去'0'
            // 如果j还没走到num2的开始，加上num2对应位置的数字
            if (j >= 0) sum += num2[j--] - '0'; // 同样减去'0'转换为数字

            // 将sum的个位数追加到结果字符串
            result += (sum % 10) + '0';
            // 更新进位
            carry = sum / 10;
        }
        // 由于结果是反的（从个位开始计算的），所以需要逆序
        reverse(result.begin(),result.end());
        return result;
    }
};
