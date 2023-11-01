//
// Created by egl1an on 2023/11/1.
//
#include "predefs.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 两个哈希表用于存放映射
        // st_map: s -> t
        // ts_map: t -> s
        unordered_map<char, char> st_map, ts_map;

        for (int i = 0; i < s.length(); ++i) {
            // 到end说明到每一个表的末尾了(哈希表中没有对应的映射)，然后把新元素映射添加进去
            if (st_map.find(s[i]) == st_map.end() && ts_map.find(t[i]) == ts_map.end()) {
                st_map[s[i]] = t[i];
                ts_map[t[i]] = s[i];
            // 如果能进到这个else if语句，说明元素存在映射来判断映射关系是否相等即可
            } else if (st_map[s[i]] != t[i] || ts_map[t[i]] != s[i]) {
                return false;
            }

        }
        return true;
    }
};