// 单调栈，保持栈中元素的单调性
//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
      int maxArea = 0;
      stack<int> indexStack; // 栈用于存储柱子的索引
      heights.push_back(0);// 在最后添加一个高度为 0 的柱子以清空栈
      for(int i = 0; i < heights.size();++i){
          while(!indexStack.empty() && heights[i] < heights[indexStack.top()]){
              int height = heights[indexStack.top()];
              indexStack.pop();
              int width = indexStack.empty() ? i : (i - indexStack.top() - 1);
              maxArea = max(maxArea,height * width);
          }
          indexStack.push(i);
      }
        return maxArea;
    }
};

