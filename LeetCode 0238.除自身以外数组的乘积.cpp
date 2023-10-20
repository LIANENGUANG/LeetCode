//
// Created by egl1an on 2023/10/10.
//
#include "predefs.h"
// a common solution is to create two additional arrays
// one holding the cumulative product from left to right
// one holding the cumulative product from right to left

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), result(n);

        // compute left cumulative product
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // compute right cumulative product
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // compute the result
        for(int i = 0; i < n; i++){
            result[i] = right[i]*left[i];
        }
        return result;

    }
};