//
// Created by egl1an on 2023/10/14.
//
// 快慢指针法
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n; // 如果数组长度小于等于2，无需处理
        }

        int slow = 2; // 从第三个元素开始检查
        for (int fast = 2; fast < n; fast++) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
};

