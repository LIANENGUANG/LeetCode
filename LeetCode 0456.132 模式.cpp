//
// Created by egl1an on 2023/11/8.
//
#include "predefs.h"

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size(), second = INT_MIN;
        stack<int> st;

        // 从右向左遍历数组
        for(int i = n -1; i >= 0; --i){
            // 如果当前元素小于次大值，说明找到了 132 元素
            // 因为栈里存了 3 元素，second存了 2 元素，只要找到 1 元素即可
            if(nums[i] < second){
                return true;
            }
            // 如果找到了大于栈顶的值，则更新次大值
            while(!st.empty() && nums[i] > st.top()){
                second = st.top();
                st.pop();
            }
            // 将当前元素压入栈中（更新最大值或者压入第一个最大值作为栈顶元素）
            st.push(nums[i]);
        }
        // 如果没有找到
        return false;
    }
};