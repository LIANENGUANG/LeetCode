//
// Created by egl1an on 2023/10/22.
//
#include "predefs.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 处理特殊情况
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1)return INT_MAX;

        // 使用long long 防止溢出，并取得他们的绝对值
        long long ldividend = abs((long long) dividend);
        long long ldivisor = abs((long long) divisor);

        // 判断结果的符号
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        // 商
        long long quotient = 0;

        while (ldividend >= ldivisor) {
            long long temp = ldivisor, multiple = 1;
            // 如果被除数大于除数的二倍
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                // 如果大于其 2 倍，倍增乘数。并且左移一次除数（放大了除数）
                multiple <<= 1;
            }
            // 减一次除数，逐渐逼近除数
            ldividend -= temp;
            // 累计之前的乘数
            quotient += multiple;
        }
        return sign * quotient;
    }
};