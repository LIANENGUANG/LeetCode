
//
// Created by egl1an on 2023/10/19.
//
#include "predefs.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();  // 获取字符串长度

        // 从字符串的开始位置开始，每次向前移动2k个位置
        for (int start = 0; start < n; start += 2 * k) {
            int end = start + k - 1;  // 确定需要反转的子串的结束位置

            // 如果计算出的结束位置超出字符串长度，将其设置为字符串的最后一个位置
            if (end >= n) end = n - 1;

            // 使用STL中的reverse方法反转从start开始的k个字符
            // 如果子串长度小于k，reverse会自动处理这种情况
            reverse(s.begin() + start, s.begin() + end + 1);
        }

        // 返回处理后的字符串
        return s;
    }
};
