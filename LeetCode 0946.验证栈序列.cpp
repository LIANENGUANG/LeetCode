//
// Created by egl1an on 2023/11/6.
//
#include "predefs.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int popIndex = 0;
        for(int num : pushed){
            // 将元素推入辅助栈
            stack.push(num);
            //循环检查并弹出栈顶元素，当它等于弹出序列的当前元素
            while(!stack.empty() && stack.top() == popped[popIndex]){
                stack.pop();
                popIndex++;
            }
        }
        // 如果栈为空，说明弹出序列是可能的
        return stack.empty();
    }
};