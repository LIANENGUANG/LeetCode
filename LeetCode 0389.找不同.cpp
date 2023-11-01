//
// Created by egl1an on 2023/11/1.
//
#include "predefs.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        // 初始化 26 个 0
        vector<int> count_s(26, 0), count_t(26, 0);// 26 代表 26 个小写字母

        for (char c: s) {
            count_s[c - 'a']++;// 统计s中每个字符的频率
        }

        for (char c: t) {
            count_t[c - 'a']++;// 统计t中每个字符的频率
        }
        for (int i = 0; i < 26; i++) {
            if (count_s[i] != count_t[i]) {
                return 'a' + i;// 找到了频率不同的字符
            }
        }
        return 'a';// 默认返回'a'，但这种情况不应该发生，因为题目保证了有一个不同的字符
    }
};
