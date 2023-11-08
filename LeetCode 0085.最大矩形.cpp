//
// Created by egl1an on 2023/11/7.
//
#include "predefs.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0; //如果矩阵为空，则返回 0
        // 用于记录最大矩形面积
        int maxArea = 0;
        // 用于存储每列连续 1 的数量
        vector<int> heights(matrix[0].size(), 0);

        // 遍历矩阵的每一行
        for (const auto &row: matrix) {
            // 更新每列连续 1 的数量，注意是连续的1
            for (size_t i = 0; i < row.size(); ++i) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            // 应用单调栈计算当前直方图的最大面积，传入参数为heights数组
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    // 单调栈计算一维直方图的最大矩形面积
    int largestRectangleArea(const vector<int> &heights) {
        int maxArea = 0; // 最大面积
        stack<int> stack; // 单调栈
        vector<int> extendedHeights = heights;
        extendedHeights.push_back(0); // 添加哨兵元素简化逻辑

        // 此处的详细原因可以到84号算法题看
        for (int i = 0; i < extendedHeights.size(); ++i) {
            while (!stack.empty() && extendedHeights[stack.top()] > extendedHeights[i]) {
                int height = extendedHeights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width); // 更新最大面积
            }
            stack.push(i); // 将当前索引推入栈中
        }

        return maxArea; // 返回最大面积
    }
};