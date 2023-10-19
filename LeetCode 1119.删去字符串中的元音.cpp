//
// Created by egl1an on 2023/10/19.
//
#include "predefs.h"

class Solution {
public:
    string removeVowels(string s) {
        // 直接在原数组上修改
        // 返回值下标
        int n = 0;
        string vowel = "aeiou";
        for (int i = 0; i < s.size(); i++) {
            // 如果没找到，说明他不是元音字母
            if (vowel.find(s[i])== string::npos) {
                s[n] = s[i];
                n++;
            }
        }
        // 注意，此时s字符串数组长度已经发生了改变，因为他删除了哪些元音字母
        s.resize(n);
        return s;
    }
};