//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // find函数用于查找一个子串或字符在主字符串中的位置。
        // 如果find函数找到了指定的子串或字符，它将返回这个子串或字符首次出现的位置（一个非负整数）。
        // 如果find函数没有找到指定的子串或字符，则它将返回一个特殊的常量值string::npos。
        // 也就是说没找到条件为假false，找到的话条件为真返回true。
        return ((s + s).substr(1,2*s.size() -2).find(s) != string::npos);

    }
};