//
// Created by egl1an on 2023/10/4.
// 快慢指针法也可以
// 保序操作题，套用过滤器模版
#include "predefs.h"

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 第一个数肯定要，后面的数和前面的不一样的我们也要，确保边界不要超出，并且是原地操作
            // 可以看出不会被提前覆盖
            if (nums[i] != 0) {
                nums[n] = nums[i];
                n++;
            }
        }
        // 将原来的 0 直接补上，相当于移动了那些 0
        while (n < nums.size()) {
            nums[n] = 0;
            n++;
        }

    }
};

int main283() {
    vector nums = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);
    for (int &num: nums) {
        cout << num << "->";
    }

}