//
// Created by egl1an on 2023/10/11.
#include "predefs.h"

// 出现过则值标记为负数
// 如果还有值为正，说明nums[i] - 1所对应的元素没有出现，如果出现了应该置为负数，
// 这是由if (nums[index] > 0) nums[index] = -nums[index];所决定的
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            // 防止索引为负，因为索引是由当前的值隐含得到的
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) nums[index] = -nums[index];
        }
        //再次遍历数组，找到正数。它们的位置表示消失的数字。
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};