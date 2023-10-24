//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        if (nums.size() <= 1) return nums; // 如果数组只有一个元素或为空，则已经排序

        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        //递归地对左右部分进行排序
        left = sortArray(left);
        right = sortArray((right));

        // 合并已经排序的左右部分
        return merge(left, right);
    }
    // 合并部分
    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> result;
        int i = 0, j = 0;

        // 当左右数组都有元素时，选择较小的元素放入结果数组
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }
        }
        //如果左数组还有元素，则添加到结果数组
        while (i < left.size()) {
            result.push_back(left[i++]);
        }
        //如果右数组还有元素，则添加到结果数组
        while (j < right.size()) {
            result.push_back(right[j++]);
        }
        return result;
    }
};