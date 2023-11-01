//
// Created by egl1an on 2023/11/1.
//
#include "predefs.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st_map, ts_map;

        for (int i = 0; i < s.length(); ++i) {
            if (st_map.find(s[i]) == st_map.end() && ts_map.find(t[i]) == ts_map.end()) {
                st_map[s[i]] = t[i];
                ts_map[t[i]] = s[i];
            } else if (st_map[s[i]] != t[i] || ts_map[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};
