//
// Created by egl1an on 2023/11/6.
//
#include "predefs.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> indexStack;// 存储索引的栈
        for (int i = 0; i < temperatures.size(); i++) {
            // 循环比较当前温度是否比栈顶温度高时，如果高则更新answer数组，否则将当前的index压栈
            // 注意栈顶元素是answer数组的当前下标
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int prevIndex = indexStack.top();
                answer[prevIndex] = i - prevIndex;
                indexStack.pop();
            }
            // 当前温度比栈顶温度低时，将当前温度的索引入栈
            indexStack.push(i);
        }
        return answer;
    }
};