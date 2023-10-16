//
// Created by egl1an on 2023/10/16.
//
#include "predefs.h"

class Sulution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;

        // find the first decreasing number from the right
        int i = n - 2;
        while( i >= 0&& nums[i] >= nums[i + 1]){
            i--;
        }

        // if the sequence is not entirely decreasing
        if(i >= 0){
            // find the number just larger than nums[i]
            int j = n - 1;
            while(nums[j] <= nums[i]){
                j--;
            }

            // swap nums[i] and nums[j]
            swap(nums[i],nums[j]);
        }
        // reverse the sequence form i + 1 to the end
        reverse(nums.begin() + i + 1,nums.end());
    }
};