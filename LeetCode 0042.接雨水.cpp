//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> monoStack; // 单调递减栈，存储索引
        int totalWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (!monoStack.empty() && height[i] > height[monoStack.top()]) {
                int top = monoStack.top();
                monoStack.pop();
                if (monoStack.empty()) {
                    // 如果栈为空，则没有左边界
                    break;
                }
                int distance = i - monoStack.top() - 1; // 计算宽度
                int bounded_height = min(height[i], height[monoStack.top()]) - height[top]; // 计算高度
                totalWater += distance * bounded_height; // 计算积水量
            }
            monoStack.push(i); // 当前柱子高度小于等于栈顶，或者栈为空，当前索引入栈
        }

        return totalWater;
    }
};
