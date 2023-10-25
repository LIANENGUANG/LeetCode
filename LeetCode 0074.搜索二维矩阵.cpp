//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 获取矩阵的行数
        int m = matrix.size();
        // 获取矩阵的列数，通过第 0 行的元素个数来确定有多少列
        int n = matrix[0].size();
        // 初始化两个指针，代表整个矩阵的首尾
        int left = 0, right = m * n - 1;

        // 使用二分查找
        while (left <= right) {
            // 定义中间索引
            int mid = left + (right - left) / 2;
            // 将一维数组索引转换为二维矩阵的行和列索引
            // 用mid来索引行号和列号
            int row = mid / n;
            int col = mid % n;

            // 检查目标值是否与当前中间值匹配
            if (matrix[row][col] == target) {
                return true;
            }
                // 如果当前中间值小于目标值，说明目标值在右侧，所以更新 left
            else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        //如果循环结束都没有找到目标值，返回 false
        return false;
    }
};