
//
// Created by egl1an on 2023/11/8.
//
#include "predefs.h"

class Solution {
public:
    string reverseWords(string s) {
        // 移除字符串收尾空格
        // 定义双指针
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') ++start;
        while (start <= end && s[end] == ' ') --end;

        // 移除多余字符串并且反转字符串
        string result;
        while (start <= end) {
            if (s[start] != ' ') result += s[start];
            else if (result.back() != ' ') result += ' ';
            ++start;
        }
        reverse(result.begin(), result.end());

        // 反转每个单词
        int wordStart = 0;
        for (int i = 0; i <= result.size(); ++i) {
            // 等于 result.size()说明到末尾的下一个标志着结束，等于' '，说明遇到了一个单词分隔空格
            if (i == result.size() || result[i] == ' ') {
                reverse(result.begin() + wordStart, result.begin() + i);
                wordStart = i + 1;
            }
        }
        return result;
    }
};