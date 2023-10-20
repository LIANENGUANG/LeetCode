//
// Created by egl1an on 2023/10/15.
//
#include "predefs.h"
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size();i++){
            if(nums[i] < nums[i - 1]){
                cnt++;
                if(cnt++ > 1){return false;}
                // 如果没有返回false则说明进行第一次改变数字
                // 改变的话入手有两个位置，i位置和 i - 1位置
                // 要么使得i - 1更小，要么使 i 位置变大
                // 但是如果i位置变大，则 i + 1位置就有可能又不满足
                // 因此应该尽可能的让 i - 1 位置变小
                // 我们尽可能地让nums[i-1]变小，但是如果不能这么做（因为它会破坏前面的非递减性），我们就让nums[i]变大
                if( i - 2 < 0||nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};