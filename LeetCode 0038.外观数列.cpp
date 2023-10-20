//
// Created by egl1an on 2023/10/20.
//
#include "predefs.h"

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        // 从第二个数开始迭代
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int j = 0;
            while (j < result.size()) {
                char currentChar = result[j];
                int count = 0;

                // 使用双指针计算连续相同字符的数量
                while (j < result.size() && result[j] == currentChar) {
                    count++;
                    j++;
                }
                current += to_string(count) + currentChar;

            }
            result = current; // 更新结果字符串，每次都要覆盖前一次的
        }
        return result;

    }
};