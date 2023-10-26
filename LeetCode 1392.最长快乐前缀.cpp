//
// Created by egl1an on 2023/10/26.
//
#include "predefs.h"

// pattern : A B A B
// LPS:      0 0 1 2

class Solution {
public:
    string longestPrefix(string s) {
        // s 主串
        int n = s.size();
        // 初始化lps 数组：最长前缀后缀数组，全部为 0
        vector<int> lps(n,0);
        // 结果字符串用于存储结果
        string result;
        // 从 i = 1开始，因为从0 开始没必要
        int i = 1;
        // 最长公共前后缀的长度，他会给 LPS 数组的赋值
        int len = 0;
        while(i < n){
            // 匹配，最长公共前后缀长度加 1，为了记录当前位置的所出现的最长公共前后缀的
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    // lps中本来就是存长度，如果当前长度失配，那么应该更新为更小的长度
                    len = lps[len -1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }


    }
};