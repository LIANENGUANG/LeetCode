//
// Created by egl1an on 2023/11/2.
//
#include "predefs.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 如果两个字符串的长度不同，直接返回false
        if(s.size() != t.size()) return false;

        // 创建一个哈希表来跟踪字符的计数
        unordered_map<char, int> counts;

        // 遍历字符串s 和 t
        for(int i = 0; i<s.size(); i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        // 遍历哈希表
        for(auto count:counts){
            // 如果有非 0 计数，说明那个数字没有被加减处理后变成 0
            // 说明他不是在两个串种出现了相同次数
            if(count.second) return false;
        }
        // 如果所有的字符都计数都相同，返回true
        return true;
    }
};