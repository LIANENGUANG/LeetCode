//
// Created by egl1an on 2023/10/20.
//
#include "predefs.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0; // i 和 j 是遍历 version1 和 version2 的指针

        // 当任何一个版本号还没有遍历完时，继续执行
        while (i < n || j < m) {
            int v1 = 0, v2 = 0; // v1 和 v2 用于存储当前遍历到的修订号

            // 读取 version1 的当前修订号
            while (i < n && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0'); // 将字符转换为整数
                i++; // 移动到下一个字符
            }

            // 读取 version2 的当前修订号
            while (j < m && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0'); // 将字符转换为整数
                j++; // 移动到下一个字符
            }

            // 比较两个修订号
            if (v1 > v2) return 1;  // 如果 version1 的修订号大于 version2 的修订号
            else if (v1 < v2) return -1; // 如果 version1 的修订号小于 version2 的修订号

            // 每次 while 循环结束都是因为出现了一个.
            i++; // 跳过 '.'
            j++; // 跳过 '.'
        }

        // 如果两个版本号完全相同或者一个版本号是另一个的前缀，则它们是相等的
        return 0;
    }
};
