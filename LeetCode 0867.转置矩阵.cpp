//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // 行数
        int m = matrix.size();
        // 列数
        int n = matrix[0].size();
        // m * n 矩阵转置是 n * m
        vector<vector<int>> transposed(n,vector<int>(m));

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};