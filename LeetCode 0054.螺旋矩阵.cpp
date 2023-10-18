//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 空行空列先判断
        if (matrix.empty() || matrix[0].empty())return {};
        int top = 0, bottom = matrix.size() - 1;  // 注意这里bottom和right位置应当调换
        int left = 0, right = matrix[0].size() - 1;  // 这里应当使用matrix[0].size()表示列数

        vector<int> result;

        while (top <= bottom && left <= right) {
            // 从左向右遍历，到最右上角
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            // 当前位置处于右上角，从上到下遍历
            for (int i = top + 1; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            // 确保剩下不止一行/列，因为原来可能只有 1 行或者 1 列
            if (top < bottom && left < right) {
                for (int j = right - 1; j > left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                for (int i = bottom; i > top; i--) {  // 注意这里少了i--，这会导致死循环
                    result.push_back(matrix[i][left]);
                }
            }
            // 缩小边界
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};
