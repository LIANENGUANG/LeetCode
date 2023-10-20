//
// Created by egl1an on 2023/10/15.
//
#include "predefs.h"
// 采用数字余数的关系
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        // 初始化一个长度原来数组一样大小的数组（开辟空间）
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[(i + k) % nums.size()] = nums[i];
        }
        for(int i = 0 ; i < nums.size();i++){
            nums[i] = result[i];
        }
    }

};