//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";//定义元音集
        int left = 0, right = s.size() - 1;
        // 对撞指针法
        while (left < right) {
            // 从左向右找第一个元音，注意这里的left++是没找到往下一个位置前进
            while (left < right && vowels.find(s[left]) == string::npos) left++;
            // 从右向左找第一个元音
            while (left < right && vowels.find(s[right]) == string::npos) right--;
            // 交换位置，注意这里的left++是找到所以移到下一个为止
            if (left < right) swap(s[left++], s[right--]);


        }
        return s;
    }
};