//
// Created by egl1an on 2023/10/15.
//


#include "predefs.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {

        vector<string> result;
        if (nums.empty()) return result;

        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            // 用一个while循环找到一个连续的序列
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            // 判断是否需要添加"->"
            if (nums[i] != start) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }
        }
        return result;

    }
};