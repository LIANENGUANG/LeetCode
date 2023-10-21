//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"

class Solution {
vector<int> addToArrayForm(vector<int>& num, int k) {
    int n = num.size(); // 获取num数组的大小
    int carry = 0, sum; // 初始化进位carry为0，sum用来暂存每一位的求和结果
    vector<int> result; // 初始化结果数组

    // 从num的最后一个元素开始往前遍历
    // 同时确保k没有被完全加完或者还有进位
    for(int i = n - 1; i >= 0 || k > 0 || carry; --i, k /= 10) {
        // 计算当前位的和：当前num的位 + k的当前位 + 上一次的进位
        // 若i已经小于0，则num[i]视为0
        sum = (i >= 0 ? num[i] : 0) + (k % 10) + carry;

        // 将sum的个位数加到result中
        result.push_back(sum % 10);

        // 更新进位carry，取sum的十位数
        carry = sum / 10;
    }

    // 因为从最低位开始存储到result，所以要逆序result数组
    reverse(result.begin(), result.end());

    return result; // 返回结果数组
}



};