//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        // 1.遍历第一行的第一列元素看看是否有 0，如果有则置整行/列为0;
        // 确定第一行是否应归零
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        // 确定第一列是否应归零
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        // 利用第一行和第一列来记录哪一行/哪一列应该归零。
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 根据标记将有 0 行 全部置为零。
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        // 根据标记将有 0 列 全部置为零。（没有fill相应的方法，因此采用二层循环）
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 处理第一行和第一列
        if (firstRowZero) fill(matrix[0].begin(), matrix[0].end(), 0);
        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }

        }
    }
};