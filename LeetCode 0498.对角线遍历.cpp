//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        // 判断是否为空
        if (mat.empty())return {};
        // 行数、列数
        int m = mat.size(), n = mat[0].size();
        // 矩阵中所有的元素个数:m * n
        vector<int> result(m * n);

        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            result[i] = mat[row][col];

            // 通过行列索引和的奇偶性判断对角线的方向
            if ((row + col) % 2 == 0) {
                // 向右上角移动
                // 1.两个边界情况
                if (col == n - 1) row++;
                else if (row == 0) col++;
                    // 2.一般情况
                else {
                    row--;
                    col++;
                }
            } else {
                // 向左下角移动
                // 1.两个边界情况
                if (row == m - 1) col++;
                else if (col == 0) row++;
                    // 2. 一般情况
                else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};