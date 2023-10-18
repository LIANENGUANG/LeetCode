//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // 方阵：行列数均相等
        int n = matrix.size();

        // 步骤 1：转置矩阵
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 步骤 2：逆序每一行的元素从开始到结尾
        for (int i = 0; i < n; ++i) {
            // 每一行利用 reverse函数操作
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};