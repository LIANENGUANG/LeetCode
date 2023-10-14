//
// Created by egl1an on 2023/10/14.
//
// prefix sum method
#include "predefs.h"
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        int sum = 0; // used to maintain the current sum
        for(int i = 0 ; i < nums.size() ;i++){
            sum += nums[i];
            result[i] = sum;
        }
        return result;
    }
};