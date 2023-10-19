//
// Created by egl1an on 2023/10/19.
//
#include "predefs.h"

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0; // 初始化start指针

        for (int end = 0; end < n; ++end) {
            // 当遇到空格或字符串的最后一个字符时
            if (s[end] == ' ' || end == n - 1) {
                // 如果end是字符串的最后一个位置，需要包括这个位置
                if (end == n - 1) {
                    reverse(s.begin() + start, s.begin() + end + 1);
                } else {
                    reverse(s.begin() + start, s.begin() + end); // 注意：reverse的结束迭代器是不包括的
                }
                start = end + 1; // 更新start为下一个单词的开始位置
            }
        }

        return s;
    }
};
